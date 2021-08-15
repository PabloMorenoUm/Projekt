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

int Board::goRight(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && j < ncols - 1) {
        if (coins[i][j + 1] == coins[i][j]) {
            return goRight(i, j + 1, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goLeft(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && j > 0) {
        if (coins[i][j - 1] == coins[i][j]) {
            return goLeft(i, j - 1, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goUp(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && i > 0) {
        if (coins[i - 1][j] == coins[i][j]) {
            return goUp(i - 1, j, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goDown(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && i < nrows - 1) {
        if (coins[i + 1][j] == coins[i][j]) {
            return goDown(i + 1, j, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goRightUp(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && i > 0 && j < ncols - 1) {
        if (coins[i - 1][j + 1] == coins[i][j]) {
            return goRightUp(i - 1, j + 1, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goRightDown(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && i < nrows - 1 && j < ncols - 1) {
        if (coins[i + 1][j + 1] == coins[i][j]) {
            return goRightDown(i + 1, j + 1, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goLeftUp(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && i > 0 && j > 0) {
        if (coins[i - 1][j - 1] == coins[i][j]) {
            return goLeftUp(i - 1, j - 1, t + 1, tEnd);
        }
    }
    return t;
}

int Board::goLeftDown(const unsigned &i, const unsigned &j, const int &t, const int &tEnd) {
    if (t < tEnd && i < nrows - 1 && j > 0) {
        if (coins[i + 1][j - 1] == coins[i][j]) {
            return goLeftDown(i + 1, j - 1, t + 1, tEnd);
        }
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
        if (coinsInLine == 4) {
            return BESTEVAL;
        }
    } else if (coin.isPlayer()) {
        if (coinsInLine == 4) { // besser: if winningConstellation
            return WORSTEVAL;
        }
    }
    return 0;
}

int Board::checkBoardWinLose() {
    int tStart = 1;
    int value{};
    int tEnd = tMaxCheckConnectFour;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            Coin &actualCoin = coins[i][j];
            value = evaluatePositionWinLose(goRight(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goLeft(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goUp(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goDown(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goRightUp(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goRightDown(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goLeftUp(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goLeftDown(i, j, tStart, tEnd), actualCoin);
            if (value == WORSTEVAL) {
                return value;
            }

            // if no losing configuration is detected, check for winning configuration
            value = evaluatePositionWinLose(goRight(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goLeft(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goUp(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goDown(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goRightUp(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goRightDown(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goLeftUp(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }

            value = evaluatePositionWinLose(goLeftDown(i, j, tStart, tEnd), actualCoin);
            if (value == BESTEVAL) {
                return value;
            }
        } // for jj
    } // for ii
    return 0;
}

double Board::evaluatePosition(const int &coinsInLine, Coin &coin) const {

    if (coin.isOpponent()) {
        if (coinsInLine ==
            2) { // bin mir hier nicht 100% sicher. wenn coinsInLine = 2, habe ich eigentlich 3in line, weil ich mit einer farbigen Münze beginne, und die nachfoolgenden zwei auf diese Farbe prüfe
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
    } else if (coin.isNeutral()) {
        return 0;
    }
}

double Board::evaluateBoard() {
    int tStart = 0;
    int tEnd = tmax;
    double value{0};
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            Coin &actualCoin = coins[i][j];
            value = value + evaluatePosition(goRight(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goLeft(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goUp(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goDown(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goRightUp(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goRightDown(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goLeftUp(i, j, tStart, tEnd), actualCoin) +
                    evaluatePosition(goLeftDown(i, j, tStart, tEnd), actualCoin); // check all lines
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

    double temp {};
    int temp2 {-1};
    int numOfSigCol{0};

    if (currentDepth % 2 == 0) {
        temp = -1;
    } else {
        temp = 1;
    }

    vector<int> availCols = detectAvailableCols();

    if (currentDepth < SEARCHTREEDEPTH) {

        double valueCurrentBoard{};

        for (int col: availCols) {

            // insert coin
            if (currentDepth % 2 == 0) {
                // virtual computers turn
                addCoin(col, false);
            } else {
                // virtual player's turn
                addCoin(col, true);
            }

            // check if four were connected by this coin:
            if (checkBoardWinLose() == -1) {
                valueCurrentBoard = -1;
            } else if (checkBoardWinLose() == 1) {
                valueCurrentBoard = 1;
            } else if (checkBoardWinLose() == 0) {
                valueCurrentBoard = searchDepthFirst(currentDepth + 1);
            }

            if (currentDepth % 2 == 0) {
                // computers turn
                if (currentDepth == 0){
                    if (valueCurrentBoard > temp) {
                        temp2 = col; // schreckliches Gebastel...
                    }
                    temp = max(temp, valueCurrentBoard);
                } else {
                    temp = max(temp, valueCurrentBoard);
                }
            } else {
                // virtual player turn
                temp = min(temp, valueCurrentBoard);
            }

            // remove coin added last:
            removeCoin(col);

        } // for

        if (currentDepth ==  0){
            // return the collum with the best chance

            // it can happen that the algorithm returns 0, but collum 0 is full
            // this means, that there is no chance of winning any more
            // 0 is an unavailable collumn however. In this case, return the first available position,
            // even if it means defeat for the computer

            // BIN NOCH NICHT SICHER, OB ICH ES HIERMIT NICHT KAPUTT MACHE!!

            std::vector<int> availablePos = Board::detectAvailableCols();
            bool available {false};
            for (int ii = 1 ; ii < availablePos.size() ; ii++) { // start by 1 on purpose, because I want to avoid 0
                if (ii == temp2){
                    available = true;
                    break; // collumn is available
                }
            }
            if (!available){
                // set the coin on the first available position
                temp2 = availablePos[0];
            }

            return temp2;
        } else {
            return temp;
        }

    } else if (currentDepth == SEARCHTREEDEPTH) {

        // just evaluate board
        double valueCurrentBoard{};
        if (checkBoardWinLose() == -1) {
            valueCurrentBoard = -1;
        } else if (checkBoardWinLose() == 1) {
            valueCurrentBoard = 1;
        } else if (checkBoardWinLose() == 0) {
            valueCurrentBoard = evaluateBoard();
        }

        temp = valueCurrentBoard;

        return temp;
    } // if
    return -99;
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
    if (countNeutralCoins) {
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

    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        // Player wirft Münze ein.
        for (int j = 0; j < ncols; ++j) {
            // Suche nach der markierten Spalte:
            Coin &hiddenCoin = hiddenCoins[j];
            if (hiddenCoin.isPlayer()) {
                hiddenCoin.makeHidden();
                addCoin(j, true);
                // check if player has won:
                if (checkBoardWinLose() == -1){
                    words.setString("Player wins!");
                    win = true;
                }

                // computer turn
                int level{0};
                int c = searchDepthFirst(level);

                // add the coin
                addCoin(c, false);
                if (checkBoardWinLose() == 1){
                    words.setString("Suck it Bitch!");
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
