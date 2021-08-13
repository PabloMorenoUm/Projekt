#include "pages/MainMenu.hpp"
#include "Board.hpp"
#include "WindowSize.hpp"
#include <iostream>

int main() {

    MainMenu game;
    game.start();

    /*WindowSize m_WindowSize;
    static constexpr unsigned nrows = 6, ncols = 7;
    Coin coins[nrows][ncols];
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
     */

    Board board;
//  erzeuge 4 derselben Farbe Münzen in einer Spalte
//    board.addCoin(2,true);
//    board.addCoin(2,true);
//    board.addCoin(2,true);

//    board.addCoin(2,false);
//    board.addCoin(2,false);
//    board.addCoin(2,false);


//    board.addCoin(4,false);
//    board.addCoin(4,false);

//    board.displayBoard();
//
//    double value, value2 {};
//    value = board.checkBoardWinLose();
//    std::cout << value << std::endl;
//    value2 = board.evaluateBoard();
//    std::cout << value2 << std::endl;


//    double output = board.searchDepthFirst(0);
//    std::cout << output << std::endl;

    return 0;
}