//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"
#include<iostream>

unsigned Board::getRow(const unsigned int &id) {
    unsigned value = id % nrows;
    if (value != 0)
        return value - 1;
    return 5;
}

unsigned Board::getColumn(const unsigned int &id) {
    return (id - 1) / nrows;
}

int Board::goRight(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getRightNeighbor() != -1) {
        unsigned id = actualCoin.getRightNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goRight(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goLeft(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLeftNeighbor() != -1) {
        unsigned id = actualCoin.getLeftNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goLeft(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goUp(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getUpperNeighbor() != -1) {
        unsigned id = actualCoin.getUpperNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goUp(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goDown(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLowerNeighbor() != -1) {
        unsigned id = actualCoin.getLowerNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goDown(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goRightUp(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getRightUpperNeighbor() != -1) {
        unsigned id = actualCoin.getRightUpperNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goRightUp(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goRightDown(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getRightLowerNeighbor() != -1) {
        unsigned id = actualCoin.getRightLowerNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goRightDown(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goLeftUp(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLeftUpperNeighbor() != -1) {
        unsigned id = actualCoin.getLeftUpperNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goLeftUp(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goLeftDown(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLeftLowerNeighbor() != -1) {
        unsigned id = actualCoin.getLeftLowerNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            return goLeftDown(neighbor, t + 1);
        }
    }
    return t;
}

double Board::evaluatePosition(const int coinsInRow , const Coin &coin) {
    // get the fill color
    const sf::Color coinColor = coin.getShape().getFillColor();
    const sf::Color questColorPlayer = coin.getPlayerColor();
    const sf::Color questColorOpponent = coin.getOpponentColor();
    const sf::Color questColorNeutral = coin.getNeutralColor();

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
    double value {};
    for(int ii = 1 ; ii <= nrows*ncols ; ii++) {
        Coin actualCoin = coins[getRow(ii)][getColumn(ii)];
        value = value + Board::evaluatePosition(actualCoin.getRightNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getLeftNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getUpperNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getLowerNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getRightUpperNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getRightLowerNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getLeftUpperNeighbor(),actualCoin) +
                Board::evaluatePosition(actualCoin.getLeftLowerNeighbor(),actualCoin); // check all lines
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
    unsigned idTemp = 0;
    for (int j = 0; j < ncols; ++j) {
        // Münzen auf dem Spielfeld:
        for (int i = 0; i < nrows; ++i) {
            ++idTemp;
            Coin &coin = coins[i][j];
            coin.setId(idTemp);
            coin.makeNeutral();
            coin.setRadius(100);
            coin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                             m_WindowSize.getY() * ((float) i + 1.8) / (nrows + 2));
        }
    }
}
