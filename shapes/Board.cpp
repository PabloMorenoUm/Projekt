//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"
#include <sstream>
using namespace sf;
using namespace std;

Board::Board() {
    for (int j = 0; j < ncols; ++j) {
        // Münzen auf dem Spielfeld:
        for (int i = 0; i < nrows; ++i) {
            Coin &coin = coins[i][j];
            coin.makeNeutral();
            coin.setRadius(100);
            coin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                             m_WindowSize.getY() * ((float) i + 1.8) / (nrows + 2));
        }
        // Beschriftung ganz unten:
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

int Board::goRight(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && j < ncols - 1) {
        if (coins[i][j + 1] == coins[i][j]) {
            return goRight(i, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goLeft(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && j > 0) {
        if (coins[i][j - 1] == coins[i][j]) {
            return goLeft(i, j - 1, t + 1);
        }
    }
    return t;
}

int Board::goUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0) {
        if (coins[i - 1][j] == coins[i][j]) {
            return goUp(i - 1, j, t + 1);
        }
    }
    return t;
}

int Board::goDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1) {
        if (coins[i + 1][j] == coins[i][j]) {
            return goDown(i + 1, j, t + 1);
        }
    }
    return t;
}

int Board::goRightUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0 && j < ncols - 1) {
        if (coins[i - 1][j + 1] == coins[i][j]) {
            return goRightUp(i - 1, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goRightDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1 && j < ncols - 1) {
        if (coins[i + 1][j + 1] == coins[i][j]) {
            return goRightDown(i + 1, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goLeftUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0 && j > 0) {
        if (coins[i - 1][j - 1] == coins[i][j]) {
            return goLeftUp(i - 1, j - 1, t + 1);
        }
    }
    return t;
}

int Board::goLeftDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1 && j > 0) {
        if (coins[i + 1][j - 1] == coins[i][j]) {
            return goLeftDown(i + 1, j - 1, t + 1);
        }
    }
    return t;
}

double Board::evaluatePosition(const int &coinsInRow, const Coin &coin) {
    // get the fill color
    const sf::Color &coinColor = coin.getShape().getFillColor();
    const sf::Color &questColorPlayer = coin.getPlayerColor();
    const sf::Color &questColorOpponent = coin.getOpponentColor();
    const sf::Color &questColorNeutral = coin.getNeutralColor();

    if (coinColor == questColorPlayer){
        if (coinsInRow == 4){
            return 1;
        } else if (coinsInRow == 3){
            return 0.1;
        } else if (coinsInRow == 2){
            return 0.01;
        }
    } else if (coinColor == questColorOpponent) {
        if (coinsInRow == 4){
            return -1;
        } else if (coinsInRow == 3){
            return -0.1;
        } else if (coinsInRow == 2){
            return -0.02; // 0.02 on purpose different from 0.01
        }
    } else if (coinColor == questColorNeutral) {
        return 0;
    }
}

double Board::evaluateBoard() {
    int tStart = 1;
    double value {};
    for(int i = 0 ; i < nrows ; ++i) {
        for (int j = 0; j < ncols; ++j) {
            Coin &actualCoin = coins[i][j];
            value = value + Board::evaluatePosition(goRight(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goLeft(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goUp(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goDown(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goRightUp(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goRightDown(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goLeftUp(i, j, tStart),actualCoin) +
                    Board::evaluatePosition(goLeftDown(i, j, tStart),actualCoin); // check all lines
        }
    }
    return value;
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
        for (auto & hiddenCoin : hiddenCoins) {
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
    for (auto & coinsRow : coins) {
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

    if(Keyboard::isKeyPressed(Keyboard::Enter)){
        for (int j = 0; j < ncols; ++j) {
            // Suche nach der markierten Spalte:
            Coin &hiddenCoin = hiddenCoins[j];
            if(hiddenCoin == hiddenCoin.getPlayerColor()) {
                hiddenCoin.makeHidden();
                // Player wirft Münze ein.
                addCoin(j, true);
                break;
            }
        }
    }
}

void Board::draw(RenderWindow &window) {
    for (int j = 0; j < ncols; ++j) {
        for (auto &coinsRow : coins) {
            window.draw(coinsRow[j].getShape());
        }
        window.draw(numbers[j].getText());
        window.draw(hiddenCoins[j].getShape());
    }
}