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

void Board::displayBoard() {

    string color{};

    char arr[nrows][ncols];

    std::cout << "Das aktuelle Spielfeld " << std::endl;
    std::cout << endl;

    for (int ii = 0; ii <= nrows-1; ++ii) {
        for (int jj = 0; jj <= ncols-1; ++jj) {

            const sf::Color &coinColor = coins[ii][jj].getShape().getFillColor();
            const sf::Color &questColorPlayer = coins[ii][jj].getPlayerColor();
            const sf::Color &questColorOpponent = coins[ii][jj].getOpponentColor();
            const sf::Color &questColorNeutral = coins[ii][jj].getNeutralColor();
            const sf::Color &questColorHidden = coins[ii][jj].getHiddenColor();

            if (coinColor == questColorPlayer) {
                arr[ii][jj] = 'r';
            } else if (coinColor == questColorOpponent) {
                arr[ii][jj] = 'y';
            } else if (coinColor == questColorNeutral) {
                arr[ii][jj] = '-';
            } else if (coinColor == questColorHidden) {
                arr[ii][jj] = 'x';
            }
            cout << " " << arr[ii][jj] << " ";
        } // for
        cout<<"\n";
    } // for
    std::cout << endl;
}


int Board::evaluatePositionWinLose(const int &coinsInLine, const Coin &coin) const {
// get the fill color
    const sf::Color &coinColor = coin.getShape().getFillColor();
    const sf::Color &questColorPlayer = coin.getPlayerColor();
    const sf::Color &questColorOpponent = coin.getOpponentColor();
    const sf::Color &questColorNeutral = coin.getNeutralColor();

    if (coinColor == questColorPlayer) {
        if (coinsInLine == 4) {
            return WORSTEVAL;
        }
    } else if (coinColor == questColorOpponent) {
        if (coinsInLine == 4) { // besser: if winningConstellation
            return BESTEVAL;
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

double Board::evaluatePosition(const int &coinsInLine, const Coin &coin) {
    // get the fill color
    const sf::Color &coinColor = coin.getShape().getFillColor();
    const sf::Color &questColorPlayer = coin.getPlayerColor();
    const sf::Color &questColorOpponent = coin.getOpponentColor();
    const sf::Color &questColorNeutral = coin.getNeutralColor();

    if (coinColor == questColorPlayer) {
        if (coinsInLine == 2) { // bin mir hier nicht 100% sicher. wenn coinsInLine = 2, habe ich eigentlich 3in line, weil ich mit einer farbigen Münze beginne, und die nachfoolgenden zwei auf diese Farbe prüfe
            return SECONDWORSTEVAL; //SECONDBESTEVAL;
        } else if (coinsInLine == 1) {
            return THIRDWORSTEVAL; //THIRDBESTEVAL;
        }
    } else if (coinColor == questColorOpponent) {
        if (coinsInLine == 2) {
            return SECONDBESTEVAL; //SECONDWORSTEVAL;
        } else if (coinsInLine == 1) {
            return THIRDBESTEVAL; //THIRDWORSTEVAL; // 0.02 on purpose different from 0.01 because negative positions are rated harder
        }
    } else if (coinColor == questColorNeutral) {
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
            Coin &actualCoin = coinRow[jj];
            if (actualCoin == actualCoin.getNeutralColor()) {
                output.push_back(jj);
                break;
            }
        }
        continue;
    }
    return output;
}


double Board::searchDepthFirst(int currentDepth) {

    double temp{};
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
                removeCoin(col);
                continue;
            } else if (checkBoardWinLose() == 1) {
                valueCurrentBoard = 1;
                removeCoin(col);
                continue;
            } else if (checkBoardWinLose() == 0) {
                valueCurrentBoard = searchDepthFirst(currentDepth + 1);
            }

            if (currentDepth == 0) {
                if (valueCurrentBoard > temp) {
                    numOfSigCol = col;
                    temp = col;
                }
            } else {
                if (currentDepth % 2 == 0) {
                    // computers turn
                    temp = max(temp, valueCurrentBoard);
                } else {
                    // virtual player turn
                    temp = min(temp, valueCurrentBoard);
                }
            } // if

            // remove coin added last:
            removeCoin(col);

        } // for
        return temp;
        int a = 1;

    } else if (currentDepth == SEARCHTREEDEPTH) {

        for (int col: availCols) {

            // insert coin
//            if (currentDepth % 2 == 0) {
//                // computers turn
//                addCoin(col, false);
//            } else {
//                // virtual player's turn
//                addCoin(col, true);
//            }

            // evaluate
            // at first, check if 4 coins are connected
            double valueCurrentBoard{};
            if (checkBoardWinLose() == -1) {
                valueCurrentBoard = -1;
            } else if (checkBoardWinLose() == 1) {
                valueCurrentBoard = 1;
            } else if (checkBoardWinLose() == 0) {
                valueCurrentBoard = evaluateBoard();
            }
            // minMax algorithm
            temp = (currentDepth % 2) ? min(valueCurrentBoard, temp) : max(valueCurrentBoard, temp);
            displayBoard();

            if (currentDepth % 2 == 0) {
                if (valueCurrentBoard > temp) {
                    //numOfSigCol = col;
                    temp = valueCurrentBoard;
                }
            } else {
                if (valueCurrentBoard < temp) {
                    //numOfSigCol = col;
                    temp = valueCurrentBoard;
                }
            }

//            // remove coin added last:
//            removeCoin(col);

        } // for
        return temp;
    } // if
    return -99;
}


void Board::markColumn(const int &col) {
    // Wie viele neutral gefärbte Münzen sind in der Spalte?
    int countNeutralCoins = 0;
    for (auto &coinsRow : coins) {
        Coin &coin = coinsRow[col];
        countNeutralCoins += (coin == coin.getNeutralColor()) ? 1 : 0;
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
        if (coin == coin.getNeutralColor()) {
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
        if (coin != coin.getNeutralColor()) {
            coin.makeNeutral();
            break;
        }
    }
}

void Board::input() {
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
            if (hiddenCoin == hiddenCoin.getPlayerColor()) {
                hiddenCoin.makeHidden();
                addCoin(j, true);
                // computer turn
                //int c = rand()%ncols; //searchDepthFirst();
                int level{0};
                int c = searchDepthFirst(level);
                addCoin(c, false);
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