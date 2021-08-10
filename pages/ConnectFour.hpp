//
// Created by Pablo Moreno Um on 08.08.21.
//

#ifndef PROJEKT_RUN_CONNECTFOUR_HPP
#define PROJEKT_RUN_CONNECTFOUR_HPP

#include "GamePage.hpp"
#include "Board.hpp"

class ConnectFour: public GamePage {
    Board board{};
    void input() override;
    void update(const float &dtAsSeconds) override;
    void draw() override;
public:
    explicit ConnectFour(std::map<Games, bool> &missionsCompleted);
};


#endif //PROJEKT_RUN_CONNECTFOUR_HPP
