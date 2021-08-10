//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"

int Board::goRight(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && j < ncols - 1) {
        if (coins[i][j + 1].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goRight(i, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goLeft(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && j > 0) {
        if (coins[i][j - 1].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goLeft(i, j - 1, t + 1);
        }
    }
    return t;
}

int Board::goUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0) {
        if (coins[i - 1][j].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goUp(i - 1, j, t + 1);
        }
    }
    return t;
}

int Board::goDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1) {
        if (coins[i + 1][j].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goDown(i + 1, j, t + 1);
        }
    }
    return t;
}

int Board::goRightUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0 && j < ncols - 1) {
        if (coins[i - 1][j + 1].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goRightUp(i - 1, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goRightDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1 && j < ncols - 1) {
        if (coins[i + 1][j + 1].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goRightDown(i + 1, j + 1, t + 1);
        }
    }
    return t;
}

int Board::goLeftUp(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i > 0 && j > 0) {
        if (coins[i - 1][j - 1].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
            return goLeftUp(i - 1, j - 1, t + 1);
        }
    }
    return t;
}

int Board::goLeftDown(const unsigned &i, const unsigned &j, const int &t) {
    if(t < tmax && i < nrows - 1 && j > 0) {
        if (coins[i + 1][j - 1].getShape().getFillColor() == coins[i][j].getShape().getFillColor()) {
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

void Board::addCoin(const unsigned int &col, bool &playersTurn) {
    for (int i = nrows - 1; i >= 0; --i) {
        Coin &coin = coins[i][col];
        if (coin.getShape().getFillColor() == coin.getNeutralColor()) {
            if (playersTurn)
                coin.makePlayer();
            else
                coin.makeOpponent();
            playersTurn = not playersTurn;
            break;
        }
    }
}

void Board::removeCoin(const unsigned int &col) {
    for (auto & coinsRow : coins) {
        Coin &coin = coinsRow[col];
        if (coin.getShape().getFillColor() != coin.getNeutralColor()) {
            coin.makeNeutral();
            break;
        }
    }
}

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
    }
}
