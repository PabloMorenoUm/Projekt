//
// Created by Pablo Moreno Um on 09.08.21.
//

#ifndef PROJEKT_RUN_BOARD_HPP
#define PROJEKT_RUN_BOARD_HPP

#include "Coin.hpp"
#include "WindowSize.hpp"

class Board {
    WindowSize m_WindowSize;
    static constexpr unsigned nrows = 6, ncols = 7;
    const int tmax = 3;
    Coin coins[nrows][ncols];
    static unsigned getRow(const unsigned &id);
    static unsigned getColumn(const unsigned &id);
public:
    Board();

    int goRight(const Coin &actualCoin, int t);
    int goLeft(const Coin &actualCoin, int t);
    int goUp(const Coin &actualCoin, int t);
    int goDown(const Coin &actualCoin, int t);
    int goRightUp(const Coin &actualCoin, int t);
    int goRightDown(const Coin &actualCoin, int t);
    int goLeftUp(const Coin &actualCoin, int t);
    int goLeftDown(const Coin &actualCoin, int t);
    double checkForGood();
    double checkForDangerous();
    double evaluate();
    void addCoin(const unsigned &col, bool &playersTurn);
    void removeCoin(const unsigned &col);
};


#endif //PROJEKT_RUN_BOARD_HPP
