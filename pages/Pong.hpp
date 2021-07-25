//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_PONG_HPP
#define PROJEKT_PONG_HPP

#include "BasicPage.hpp"
#include "../shapes/Ball.hpp"
#include "../shapes/Bat.hpp"

class Pong: public BasicPage {
    int score = 0;
    int lives = 3;
    Bat bat{m_WindowSize.getX() / 2, m_WindowSize.getY() - 70};
    Ball ball{m_WindowSize.getX() / 2, 20};
    Words hud{writeScore(), 200, m_WindowSize.getX() * 2 / 5, m_WindowSize.getY() / 10};
    std::string writeScore() const;
    void input() override;
    void update(float) override;
    void draw() override;
public:
    Pong();
};


#endif //PROJEKT_PONG_HPP
