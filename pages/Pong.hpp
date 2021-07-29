//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_PONG_HPP
#define PROJEKT_PONG_HPP

#include "GamePage.hpp"
#include "../shapes/Ball.hpp"
#include "../shapes/Bat.hpp"

class Pong: public GamePage {
    unsigned lives = 3;
    Bat bat{m_WindowSize.getX() / 2, m_WindowSize.getY() - 70};
    Ball ball{m_WindowSize.getX() / 2, 20};
    std::string writeScore() const override;
    void input() override;
    void update(const float &dtAsSeconds) override;
    void draw() override;
public:
    explicit Pong(std::map<std::string, bool> &missionsCompleted);
};


#endif //PROJEKT_PONG_HPP
