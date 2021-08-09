//
// Created by Pablo Moreno Um on 09.08.21.
//

#include "Board.hpp"

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
            goLeft(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goUp(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getUpperNeighbor() != -1) {
        unsigned id = actualCoin.getUpperNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            goUp(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goDown(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLowerNeighbor() != -1) {
        unsigned id = actualCoin.getLowerNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            goDown(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goRightUp(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getRightUpperNeighbor() != -1) {
        unsigned id = actualCoin.getRightUpperNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            goRightUp(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goRightDown(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getRightLowerNeighbor() != -1) {
        unsigned id = actualCoin.getRightLowerNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            goRightDown(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goLeftUp(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLeftUpperNeighbor() != -1) {
        unsigned id = actualCoin.getLeftUpperNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            goLeftUp(neighbor, t + 1);
        }
    }
    return t;
}

int Board::goLeftDown(const Coin &actualCoin, int t) {
    if(t < tmax && actualCoin.getLeftLowerNeighbor() != -1) {
        unsigned id = actualCoin.getLeftLowerNeighbor();
        Coin &neighbor = coins[getRow(id)][getColumn(id)];
        if (neighbor.getShape().getFillColor() == actualCoin.getShape().getFillColor()) {
            goLeftDown(neighbor, t + 1);
        }
    }
    return t;
}

double Board::checkForGood() {
    // still to be done
    return -1;
}

double Board::checkForDangerous() {
    // still to be done
    return -1;
}

double Board::evaluate() {
    // still to be done
    return -1;
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
