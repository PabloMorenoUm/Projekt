//
// Created by Pablo Moreno Um on 19.07.21.
//

#ifndef PROJEKT_BAT_HPP
#define PROJEKT_BAT_HPP

#include "BallBat.hpp"
#include "../helpers/Direction.hpp"
#include "../helpers/WindowSize.hpp"
#include <SFML/Graphics.hpp>

class Bat: public BallBat {
    Direction m_RightPressed;
    Direction m_LeftPressed;
    WindowSize m_WindowSize;
    void moveLeft(float);
    void moveRight(float);
public:
    Bat(float startX, float startY);
    void input();
    void update(float) override;

};


#endif //PROJEKT_BAT_HPP
