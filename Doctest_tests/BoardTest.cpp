//
// Created by Pablo Moreno Um on 17.08.21.
//

#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <sstream>

TEST_CASE("Board") {
    // Test mit kritischem Board:
    Board board;
    // Spalte 1:
    board.addCoin(0,false);
    board.addCoin(0,false);
    board.addCoin(0,false);
    board.addCoin(0,true);
    board.addCoin(0,false);
    board.addCoin(0,true);

    // Spalte 2:
    board.addCoin(1,false);
    board.addCoin(1,false);
    board.addCoin(1,true);

    // Spalte 3:
    board.addCoin(2,false);
    board.addCoin(2,false);
    board.addCoin(2,false);
    board.addCoin(2,true);
    board.addCoin(2,true);
    board.addCoin(2,true);

    // Spalte 4:
    board.addCoin(3,true);
    board.addCoin(3,true);
    board.addCoin(3,false);
    board.addCoin(3,true);
    board.addCoin(3,true);
    board.addCoin(3,true);

    // Spalte 6:
    board.addCoin(5,false);
    board.addCoin(5,true);
    board.addCoin(5,true);
    board.addCoin(5,false);
    board.addCoin(5,true);
    board.addCoin(5,true);

    // Spalte 7:
    board.addCoin(6,false);
    board.addCoin(6,false);
    board.addCoin(6,false);
    board.addCoin(6,true);

    std::stringstream ss;
    board.displayBoardOnConsole(ss);
    std::string expectedString =
            "Das aktuelle Spielfeld \n\n"
            " r  -  r  r  -  r  - \n"
            " y  -  r  r  -  r  - \n"
            " r  -  r  r  -  y  r \n"
            " y  r  y  y  -  r  y \n"
            " y  y  y  r  -  r  y \n"
            " y  y  y  r  -  y  y \n\n";
    CHECK_EQ(ss.str(), expectedString);

    CHECK_EQ(board.checkBoardWinLose(), 0);
    // Werte selber zusammenzählen (von links nach rechts spaltenweise):
    double value =
            - .02 + .1 * 2 + .01 * 3 + .1 + .1 * 3
            - .02 - .1 + .01 * 7 + .01 * 4 + .1
            - .02 * 2 - .1 - .02 * 5 - .02 * 3 - .1 + .01 + .1 * 2 + .01 * 4 * .1 + .1 * 3
            - .02 * 2 - .1 - .02 * 4 - .1 - .02 * 2 - .1 + .01 + .1 - .02 - .02
            - .02 - .02 * 2 + .01 - .02 * 2 - .02 + .01 * 2
            - .02 * 2 + .01 + .1 + .01 * 3 + .01 + .1;
    CHECK_EQ(board.evaluateBoard(), doctest::Approx(.68).epsilon(.00001));

    // Insert into second column:
    CHECK_EQ(board.searchDepthFirst(0), 1);
}