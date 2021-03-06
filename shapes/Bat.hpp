//
// Created by Pablo Moreno Um on 19.07.21.
//

#ifndef PROJEKT_BAT_HPP
#define PROJEKT_BAT_HPP

#include "BallBat.hpp"
#include "Direction.hpp"
#include "WindowSize.hpp"

class Bat: public BallBat {
    Direction m_RightPressed{};
    Direction m_LeftPressed{};
    WindowSize m_WindowSize;
    void moveLeft(const float &elapsedTime);
    void moveRight(const float &elapsedTime);
public:
    Bat(const float &startX, const float &startY);
    void input();
    void update(const float &elapsedTime) override;
};


#endif //PROJEKT_BAT_HPP
