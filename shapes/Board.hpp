//
// Created by Pablo Moreno Um on 09.08.21.
//

#ifndef PROJEKT_RUN_BOARD_HPP
#define PROJEKT_RUN_BOARD_HPP

#include "Coin.hpp"
#include "WindowSize.hpp"
#include "Words.hpp"

class Board {
    // Bildschirmmaße:
    WindowSize m_WindowSize;
    // Dimension des Spielfelds:
    static constexpr unsigned nrows = 6, ncols = 7;
    const int tmax = 3;
    // Spielfeldmünzen:
    Coin coins[nrows][ncols];
    // Unsichtbare Münzen als Spaltenmarker, damit der User weiß, welche Spalte gerade ausgewählt ist:
    Coin hiddenCoins[ncols];
    // Spaltennummerierung, damit der User weiß, wo er tippen soll ;-):
    Words numbers[ncols];

    // Konstanten:
    const int BESTEVAL {1};
    const double SECONDBESTEVAL {0.1};
    const double THIRDBESTEVAL {0.01};
    const double THIRDWORSTEVAL {-0.02};
    const double SECONDWORSTEVAL {-0.1};
    const int WORSTEVAL {-1};


    int goRight(const unsigned &i, const unsigned &j, const int &t);
    int goLeft(const unsigned &i, const unsigned &j, const int &t);
    int goUp(const unsigned &i, const unsigned &j, const int &t);
    int goDown(const unsigned &i, const unsigned &j, const int &t);
    int goRightUp(const unsigned &i, const unsigned &j, const int &t);
    int goRightDown(const unsigned &i, const unsigned &j, const int &t);
    int goLeftUp(const unsigned &i, const unsigned &j, const int &t);
    int goLeftDown(const unsigned &i, const unsigned &j, const int &t);

    void markColumn(const int &col);
    void markColumnComputer(const int &col);
    void addCoin(const unsigned &col, const bool &playersTurn);
    void removeCoin(const unsigned &col);
    int findBestPosition();
public:
    Board();
    int evaluatePositionWinLoose(const int &coinsInLine, const Coin &coin);
    int checkBoardWinLoose();
    double evaluatePosition(const int &coinsInLine, const Coin &coin);
    double evaluateBoard();
    void input();
    void draw(sf::RenderWindow &window);
};


#endif //PROJEKT_RUN_BOARD_HPP
