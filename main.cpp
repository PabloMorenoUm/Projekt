#include "pages/MainMenu.hpp"
#include "Board.hpp"
#include "WindowSize.hpp"
#include <iostream>

int main() {

    MainMenu game;
    game.start();


//    // Test mit kritischem Board:
//    Board board;
//    // Spalte 1:
//    board.addCoin(0,false);
//    board.addCoin(0,false);
//    board.addCoin(0,false);
//    board.addCoin(0,true);
//    board.addCoin(0,false);
//    board.addCoin(0,true);
//
//    // Spalte 2:
//    board.addCoin(1,false);
//    board.addCoin(1,false);
//    board.addCoin(1,true);
//
//    // Spalte 3:
//    board.addCoin(2,false);
//    board.addCoin(2,false);
//    board.addCoin(2,false);
//    board.addCoin(2,true);
//    board.addCoin(2,true);
//    board.addCoin(2,true);
//
//    // Spalte 4:
//    board.addCoin(3,true);
//    board.addCoin(3,true);
//    board.addCoin(3,false);
//    board.addCoin(3,true);
//    board.addCoin(3,true);
//    board.addCoin(3,true);
//
//    // Spalte 6:
//    board.addCoin(5,false);
//    board.addCoin(5,true);
//    board.addCoin(5,true);
//    board.addCoin(5,false);
//    board.addCoin(5,true);
//    board.addCoin(5,true);
//
//    // Spalte 7:
//    board.addCoin(6,false);
//    board.addCoin(6,false);
//    board.addCoin(6,false);
//    board.addCoin(6,true);
//
//    board.displayBoardOnConsole();
//
//    double value, value2 {};
//    value = board.checkBoardWinLose();
//    std::cout << value << std::endl;
//    value2 = board.evaluateBoard();
//    std::cout << value2 << std::endl;
//
//    double output = board.searchDepthFirst(0);
//    std::cout << "I will insert into column: " << std::endl;
//    std::cout << output << std::endl;

    return 0;
}