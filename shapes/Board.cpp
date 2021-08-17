//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"
#include <sstream>
#include <algorithm>

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

void Board::displayBoardOnConsole(ostream &os) {

    os << "Das aktuelle Spielfeld " << endl;
    os << endl;

    for (int ii = 0; ii <= nrows - 1; ++ii) {
        for (int jj = 0; jj <= ncols - 1; ++jj) {

            Coin &coin = coins[ii][jj];

            os << " " << (coin.isPlayer() ? 'r' : (coin.isOpponent() ? 'y' : (coin.isNeutral() ? '-' : 'x'))) << " ";
        } // for
        os << "\n";
    } // for
    os << endl;
}

int Board::evaluatePositionWinLose(const int &coinsInLine, Coin &coin) const {

    if (coinsInLine == tmax) { // besser: if winningConstellation
        if (coin.isOpponent())
            return BESTEVAL;
        else if (coin.isPlayer())
            return WORSTEVAL;
    }
    return 0;
}

int Board::checkDirections(const int &i, const int &j, const int &val) {
    int value;

    for (auto &horiz: horizStates) {
        for (auto &vertic: verticStates) {
            if (horiz != NONE || vertic != NONE) {
                value = evaluatePositionWinLose(go(i, j, tStart, horiz, vertic), coins[i][j]);
                if (value == val)
                    return value;
            }
        }
    }
    return 0;
}

int Board::checkBoardWinLose() {
    int value;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            value = checkDirections(i, j, WORSTEVAL);
            if (value != 0) {
                return value;
            }

            // if no losing configuration is detected, check for winning configuration
            value = checkDirections(i, j, BESTEVAL);
            if (value != 0) {
                return value;
            }
        } // for jj
    } // for ii
    return 0;
}

double Board::evaluatePosition(const int &coinsInLine, Coin &coin) const {

    bool secondCondition = coinsInLine == tmax - 1;
    bool thirdCondition = coinsInLine == tmax - 2;

    if (coin.isOpponent()) {
        /* bin mir hier nicht 100% sicher. wenn coinsInLine = 2, habe ich eigentlich 3in line,
         * weil ich mit einer farbigen Münze beginne, und die nachfoolgenden zwei auf diese Farbe prüfe
         */
        return secondCondition ? SECONDBESTEVAL : (thirdCondition ? THIRDBESTEVAL : 0);
    } else if (coin.isPlayer()) {
        // 0.02 on purpose different from 0.01 because negative positions are rated harder
        return secondCondition ? SECONDWORSTEVAL : (thirdCondition ? THIRDWORSTEVAL : 0);
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

    bool computersTurn = currentDepth % 2 == 0, gameFinished, depth0 = currentDepth == 0;

    double temp = computersTurn ? -1 : 1;
    int temp2{-1};

    vector<int> availCols = detectAvailableCols();

    if (currentDepth < SEARCHTREEDEPTH) {

        double valueCurrentBoard;

        for (auto &col: availCols) {

            // insert coin
            addCoin(col, not computersTurn);

            // check if four were connected by this coin:
            gameFinished = checkBoardWinLose() != 0;
            valueCurrentBoard = gameFinished ? checkBoardWinLose() : searchDepthFirst(currentDepth + 1);

            if (computersTurn) {
                if (depth0 && valueCurrentBoard > temp)
                    temp2 = col; // schreckliches Gebastel...

                temp = max(temp, valueCurrentBoard);
            } else
                // virtual player turn
                temp = min(temp, valueCurrentBoard);

            // remove coin added last:
            removeCoin(col);

        } // for

        if (depth0) {
            // return the column with the best chance

            // it can happen that the algorithm returns 0, but column 0 is full
            // this means, that there is no chance of winning any more
            // 0 is an unavailable column, however. In this case, return the first available position,
            // even if it means defeat for the computer

            // BIN NOCH NICHT SICHER, OB ICH ES HIERMIT NICHT KAPUTT MACHE!!
            if (find(availCols.begin(), availCols.end(), temp2) == availCols.end())
                temp2 = availCols.at(0);

            return temp2;
        } else
            return temp;

    } else {
        // just evaluate board
        gameFinished = checkBoardWinLose() != 0;
        return gameFinished ? checkBoardWinLose() : evaluateBoard();
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
    if (countNeutralCoins && !playerWinState && !playerLoseState) {
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

bool Board::isTie() {
    unsigned numNeutralCoins = 0;
    for (auto &coinsRow: coins) {
        for (auto &coin : coinsRow) {
            numNeutralCoins += coin.isNeutral();
        }
    }
    return (numNeutralCoins == 0) && !playerWinState && !playerLoseState;
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
        playerWins = playerWinState;
        playerLoses = playerLoseState;
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
                    playerWinState = true;
                }

                // computer turn
                if (!playerWinState) {
                    addCoin((int) searchDepthFirst(0), false);
                    if (checkBoardWinLose() == 1) {
                        words.setString("Suck it, Bitch! Press [P].");
                        playerLoseState = true;
                    }
                }
                break;
            }
        }
    }

    if (isTie()) {
        words.setString("Tie. Press [Esc].");
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

bool Board::isPlayerWins() const {
    return playerWins;
}

bool Board::isPlayerLoses() const {
    return playerLoses;
}
