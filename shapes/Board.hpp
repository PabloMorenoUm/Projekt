//
// Created by Pablo Moreno Um on 09.08.21.
//

#ifndef PROJEKT_RUN_BOARD_HPP
#define PROJEKT_RUN_BOARD_HPP

#include "Coin.hpp"
#include "WindowSize.hpp"
#include "Words.hpp"

class Board {
    WindowSize m_WindowSize;
    static constexpr unsigned nrows = 6, ncols = 7;
    const int tmax = 3;
    Coin coins[nrows][ncols];
    Coin hiddenCoins[ncols];
    Words numbers[ncols];

    int goRight(const unsigned &i, const unsigned &j, const int &t);
    int goLeft(const unsigned &i, const unsigned &j, const int &t);
    int goUp(const unsigned &i, const unsigned &j, const int &t);
    int goDown(const unsigned &i, const unsigned &j, const int &t);
    int goRightUp(const unsigned &i, const unsigned &j, const int &t);
    int goRightDown(const unsigned &i, const unsigned &j, const int &t);
    int goLeftUp(const unsigned &i, const unsigned &j, const int &t);
    int goLeftDown(const unsigned &i, const unsigned &j, const int &t);

    void markColumn(const int &col);

    void addCoin(const unsigned &col, const bool &playersTurn);
    void removeCoin(const unsigned &col);
public:
    Board();

    double evaluatePosition(const int &coinsInRow, const Coin &coin);
    double evaluateBoard();
    void input();
    void draw(sf::RenderWindow &window);
};


#endif //PROJEKT_RUN_BOARD_HPP
