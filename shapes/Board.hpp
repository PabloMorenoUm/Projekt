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
    const int tStart = 0, tmax = 3;
    // Spielfeldmünzen:
    Coin coins[nrows][ncols];
    // Unsichtbare Münzen als Spaltenmarker, damit der User weiß, welche Spalte gerade ausgewählt ist:
    Coin hiddenCoins[ncols];
    // Spaltennummerierung, damit der User weiß, wo er tippen soll ;-):
    Words numbers[ncols];

    bool win = false, lose = false, winState = false, loseState = false;

    // Konstanten:
    const int BESTEVAL {1};
    const double SECONDBESTEVAL {0.1};
    const double THIRDBESTEVAL {0.01};
    const double THIRDWORSTEVAL {-0.02};
    const double SECONDWORSTEVAL {-0.1};
    const int WORSTEVAL {-1};
    const int SEARCHTREEDEPTH {4};


    int goRight(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goLeft(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goUp(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goDown(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goRightUp(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goRightDown(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goLeftUp(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
    int goLeftDown(const unsigned &i, const unsigned &j, const int &t, const int &tEnd);
//    std::vector<int> detectAvailableCols();
//    void markColumn(const int &col);
//    void addCoin(const unsigned &col, const bool &playersTurn);
//    void removeCoin(const unsigned &col);

public:
    Board();

    // temporary:
    std::vector<int> detectAvailableCols();
    void markColumn(const int &col);
    void addCoin(const unsigned &col, const bool &playersTurn);
    void removeCoin(const unsigned &col);

    void displayBoardOnConsole(); // Konsolenanzeige des Spielfelds:
    int evaluatePositionWinLose(const int &coinsInLine, Coin &coin) const;
    int checkBoardWinLose();
    double searchDepthFirst(int currentDepth);
    double evaluatePosition(const int &coinsInLine, Coin &coin) const;
    double evaluateBoard();
    void input(Words &words);
    void draw(sf::RenderWindow &window);

    bool isWin() const;

    bool isLose() const;
};


#endif //PROJEKT_RUN_BOARD_HPP
