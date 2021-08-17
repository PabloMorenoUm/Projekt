//
// Created by Pablo Moreno Um on 09.08.21.
//

#ifndef PROJEKT_RUN_BOARD_HPP
#define PROJEKT_RUN_BOARD_HPP

#include "Coin.hpp"
#include "Orientation.hpp"
#include "WindowSize.hpp"
#include "Words.hpp"

class Board {
    // Bildschirmmaße:
    WindowSize m_WindowSize;
    // Dimension des Spielfelds:
    static constexpr unsigned nrows = 6, ncols = 7;
    // Spielfeldmünzen:
    Coin coins[nrows][ncols];
    // Unsichtbare Münzen als Spaltenmarker, damit der User weiß, welche Spalte gerade ausgewählt ist:
    Coin hiddenCoins[ncols];
    // Spaltennummerierung, damit der User weiß, wo er tippen soll ;-):
    Words numbers[ncols];

    std::vector<Orientation> horizStates = {RIGHT, LEFT, NONE}, verticStates = {UP, DOWN, NONE};
    bool playerWins = false, playerLoses = false, playerWinState = false, playerLoseState = false;

    // Konstanten:
    const int tStart = 0, tmax = 3, BESTEVAL {1}, WORSTEVAL {-1}, SEARCHTREEDEPTH {4};
    const double SECONDBESTEVAL {0.1}, THIRDBESTEVAL {0.01}, THIRDWORSTEVAL {-0.02}, SECONDWORSTEVAL {-0.1};

    int go(const unsigned &i, const unsigned &j, const int &t, const Orientation &horizontal,
           const Orientation &vertical);

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
    bool isTie();

    void displayBoard(std::ostream &os); // Konsolenanzeige des Spielfelds:
    int evaluatePositionWinLose(const int &coinsInLine, Coin &coin) const;
    int checkDirections(const int &i, const int &j, const int &val);
    int checkBoardWinLose();
    double searchDepthFirst(int currentDepth);
    double evaluatePosition(const int &coinsInLine, Coin &coin) const;
    double evaluateBoard();
    void input(Words &words);
    void draw(sf::RenderWindow &window);

    bool isPlayerWins() const;
    bool isPlayerLoses() const;
};


#endif //PROJEKT_RUN_BOARD_HPP
