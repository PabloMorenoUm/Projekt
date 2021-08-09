#include "pages/MainMenu.hpp"
/*#include "Board.hpp"
#include "WindowSize.hpp"
#include <iostream>*/

int main() {
    MainMenu game;
    game.start();
    /*
     * künftiger Test?!?
    WindowSize m_WindowSize;
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
    Board board;
    std::cout << board.goRight(coins[0][0], 0) << std::endl;*/

    return 0;
}