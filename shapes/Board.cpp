//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace sf;
using namespace std;

Board::Board() {
    for (int j = 0; j < ncols; ++j) {
        // Münzen auf dem Spielfeld mit GUI-Koordinaten relativ zu den Bildschirmmaßen versehen:
        for (int i = 0; i < nrows; ++i) {
            Coin &coin = coins[i][j];
            coin.makeNeutral();
            coin.setRadius(100);
            coin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                             m_WindowSize.getY() * ((float) i + 1.8) / (nrows + 2));
        }
        // Beschriftung unter den Spielfeldmünzen:
        std::stringstream ss;
        ss << j + 1;
        Words &number = numbers[j];
        number.setString(ss.str());
        number.setSize(70);
        number.setPosition(m_WindowSize.getX() * ((float) j + .45) / ncols,
                           m_WindowSize.getY() * 19 / 20);

        // Anzeige "Auswahlmöglichkeit Spalte" über dem Spielfeld:
        Coin &hiddenCoin = hiddenCoins[j];
        hiddenCoin.makeHidden();
        hiddenCoin.setRadius(100);
        hiddenCoin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                               m_WindowSize.getY() * .8 / (nrows + 2));
    }
}

int Board::go(const unsigned int &i, const unsigned int &j, const int &t, const Orientation &horizontal,
              const Orientation &vertical) {
    bool horizCond, verticCond;
    unsigned iNew, jNew;

    switch (horizontal) {
        case RIGHT:
            horizCond = j < ncols - 1;
            jNew = j + 1;
            break;
        case LEFT:
            horizCond = j > 0;
            jNew = j - 1;
            break;
        default:
            horizCond = true;
            jNew = j;
    }

    switch (vertical) {
        case DOWN:
            verticCond = i < nrows - 1;
            iNew = i + 1;
            break;
        case UP:
            verticCond = i > 0;
            iNew = i - 1;
            break;
        default:
            verticCond = true;
            iNew = i;
    }

    if (t < tmax && horizCond && verticCond) {
        if (coins[iNew][jNew] == coins[i][j])
            return go(iNew, jNew, t + 1, horizontal, vertical);
    }
    return t;
}

void Board::displayBoardOnConsole() {

    string color{};

    char arr[nrows][ncols];

    std::cout << "Das aktuelle Spielfeld " << std::endl;
    std::cout << endl;

    for (int ii = 0; ii <= nrows - 1; ++ii) {
        for (int jj = 0; jj <= ncols - 1; ++jj) {

            Coin &coin = coins[ii][jj];

            if (coin.isPlayer()) {
                arr[ii][jj] = 'r';
            } else if (coin.isOpponent()) {
                arr[ii][jj] = 'y';
            } else if (coin.isNeutral()) {
                arr[ii][jj] = '-';
            } else if (coin.isHidden()) {
                arr[ii][jj] = 'x';
            }
            cout << " " << arr[ii][jj] << " ";
        } // for
        cout << "\n";
    } // for
    std::cout << endl;
}

int Board::evaluatePositionWinLose(const int &coinsInLine, Coin &coin) const {

    if (coin.isOpponent()) {
        if (coinsInLine == tmax) {
            return BESTEVAL;
        }
    } else if (coin.isPlayer()) {
        if (coinsInLine == tmax) { // besser: if winningConstellation
            return WORSTEVAL;
        }
    }
    return 0;
}

int Board::checkBoardWinLose() {
    int value;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            Coin &actualCoin = coins[i][j];
            for (auto &horiz: horizStates) {
                for (auto &vertic: verticStates) {
                    if (horiz != NONE || vertic != NONE) {
                        value = evaluatePositionWinLose(go(i, j, tStart, horiz, vertic), actualCoin);
                        if (value == WORSTEVAL)
                            return value;
                    }
                }
            }

            // if no losing configuration is detected, check for winning configuration
            for (auto &horiz: horizStates) {
                for (auto &vertic: verticStates) {
                    if (horiz != NONE || vertic != NONE) {
                        value = evaluatePositionWinLose(go(i, j, tStart, horiz, vertic), actualCoin);
                        if (value == BESTEVAL)
                            return value;
                    }
                }
            }
        } // for jj
    } // for ii
    return 0;
}

double Board::evaluatePosition(const int &coinsInLine, Coin &coin) const {

    if (coin.isOpponent()) {
        /* bin mir hier nicht 100% sicher. wenn coinsInLine = 2, habe ich eigentlich 3in line,
         * weil ich mit einer farbigen Münze beginne, und die nachfoolgenden zwei auf diese Farbe prüfe
         */
        if (coinsInLine == 2) {
            return SECONDBESTEVAL;
        } else if (coinsInLine == 1) {
            return THIRDBESTEVAL;
        }
    } else if (coin.isPlayer()) {
        if (coinsInLine == 2) {
            return SECONDWORSTEVAL;
        } else if (coinsInLine == 1) {
            return THIRDWORSTEVAL; // 0.02 on purpose different from 0.01 because negative positions are rated harder
        }
    }
    return 0;
}

double Board::evaluateBoard() {
    double value{0};
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            for (auto &horiz: horizStates) {
                for (auto &vertic: verticStates) {
                    if (horiz != NONE || vertic != NONE)
                        value += evaluatePosition(go(i, j, tStart, horiz, vertic), coins[i][j]);
                }
            }
        }
    }
    return value;
}

vector<int> Board::detectAvailableCols() {
    vector<int> output;
    for (int jj = 0; jj < ncols; ++jj) {
        for (auto &coinRow : coins) {
            if (coinRow[jj].isNeutral()) {
                output.push_back(jj);
                break;
            }
        }
    }
    return output;
}

double Board::searchDepthFirst(int currentDepth) {

    double temp = (currentDepth % 2 == 0) ? -1 : 1;
    int temp2{-1};

    vector<int> availCols = detectAvailableCols();

    if (currentDepth < SEARCHTREEDEPTH) {

        double valueCurrentBoard;

        for (int col: availCols) {

            // insert coin
            if (currentDepth % 2 == 0)
                // virtual computers turn
                addCoin(col, false);
            else
                // virtual player's turn
                addCoin(col, true);

            // check if four were connected by this coin:
            if (checkBoardWinLose() != 0)
                valueCurrentBoard = checkBoardWinLose();
            else
                valueCurrentBoard = searchDepthFirst(currentDepth + 1);

            if (currentDepth % 2 == 0) {
                // computers turn
                if (currentDepth == 0 && valueCurrentBoard > temp)
                    temp2 = col; // schreckliches Gebastel...

                temp = max(temp, valueCurrentBoard);
            } else
                // virtual player turn
                temp = min(temp, valueCurrentBoard);

            // remove coin added last:
            removeCoin(col);

        } // for

        if (currentDepth == 0) {
            // return the column with the best chance

            // it can happen that the algorithm returns 0, but column 0 is full
            // this means, that there is no chance of winning any more
            // 0 is an unavailable column, however. In this case, return the first available position,
            // even if it means defeat for the computer

            // BIN NOCH NICHT SICHER, OB ICH ES HIERMIT NICHT KAPUTT MACHE!!
            if (find(availCols.begin(), availCols.end(), temp2) == availCols.end())
                temp2 = availCols.at(0);

            return temp2;
        } else {
            return temp;
        }

    } else {

        // just evaluate board
        if (checkBoardWinLose() != 0)
            temp = checkBoardWinLose();
        else
            temp = evaluateBoard();

        return temp;
    }
}

void Board::markColumn(const int &col) {
    // Wie viele neutral gefärbte Münzen sind in der Spalte?
    int countNeutralCoins = 0;
    for (auto &coinsRow : coins) {
        Coin &coin = coinsRow[col];
        countNeutralCoins += (coin.isNeutral()) ? 1 : 0;
    }
    /* Falls es keine neutralen Münzen gibt, ist die Spalte voll
     * => Die Spalte soll NICHT markiert werden
     * => Die folgende if-Bedingung soll NICHT aufgerufen werden.
     * Ansonsten soll die Spalte schon markiert werden.
     */
    if (countNeutralCoins && !winState && !loseState) {
        for (auto &hiddenCoin : hiddenCoins) {
            hiddenCoin.makeHidden();
        }
        hiddenCoins[col].makePlayer();
    }
}

void Board::addCoin(const unsigned int &col, const bool &playersTurn) {
    for (int i = nrows - 1; i >= 0; --i) {
        Coin &coin = coins[i][col];
        if (coin.isNeutral()) {
            if (playersTurn)
                coin.makePlayer();
            else
                coin.makeOpponent();
            break;
        }
    }
}

void Board::removeCoin(const unsigned int &col) {
    for (auto &coinsRow : coins) {
        Coin &coin = coinsRow[col];
        if (!coin.isNeutral()) {
            coin.makeNeutral();
            break;
        }
    }
}

void Board::input(Words &words) {
    if (Keyboard::isKeyPressed(Keyboard::Num1))
        markColumn(0);

    if (Keyboard::isKeyPressed(Keyboard::Num2))
        markColumn(1);

    if (Keyboard::isKeyPressed(Keyboard::Num3))
        markColumn(2);

    if (Keyboard::isKeyPressed(Keyboard::Num4))
        markColumn(3);

    if (Keyboard::isKeyPressed(Keyboard::Num5))
        markColumn(4);

    if (Keyboard::isKeyPressed(Keyboard::Num6))
        markColumn(5);

    if (Keyboard::isKeyPressed(Keyboard::Num7))
        markColumn(6);

    if (Keyboard::isKeyPressed(Keyboard::P)) {
        win = winState;
        lose = loseState;
    }

    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        // Player wirft Münze ein.
        for (int j = 0; j < ncols; ++j) {
            // Suche nach der markierten Spalte:
            Coin &hiddenCoin = hiddenCoins[j];
            if (hiddenCoin.isPlayer()) {
                hiddenCoin.makeHidden();
                addCoin(j, true);
                // check if player has won:
                if (checkBoardWinLose() == -1) {
                    words.setString("Player wins! Press [P].");
                    winState = true;
                }

                // computer turn
                int level{0};
                int c = searchDepthFirst(level);

                // add the coin
                addCoin(c, false);
                if (checkBoardWinLose() == 1) {
                    words.setString("Suck it Bitch! Press [P].");
                    loseState = true;
                }
                break;
            }
        }
    }
}

void Board::draw(RenderWindow &window) {
    for (int j = 0; j < ncols; ++j) {
        // Spielfeldmünzen in die GUI bringen
        for (auto &coinsRow : coins) {
            window.draw(coinsRow[j].getShape());
        }
        // Spaltenbeschriftung in die GUI bringen
        window.draw(numbers[j].getText());
        // Spaltenmarker in die GUI bringen
        window.draw(hiddenCoins[j].getShape());
    }
}

bool Board::isWin() const {
    return win;
}

bool Board::isLose() const {
    return lose;
}
