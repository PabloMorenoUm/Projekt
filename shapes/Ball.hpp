//
// Created by Pablo Moreno Um on 19.07.21.
//

#ifndef PROJEKT_BALL_HPP
#define PROJEKT_BALL_HPP

#include "BallBat.hpp"
#include <SFML/Graphics.hpp>

class Ball: public BallBat {
    bool signX = true, signY = true;
    const float speedConst = 1.25f;
public:
    Ball(float startX, float startY);
    void reboundSides();
    void reboundBatOrTop();
    void hitBottom();
    void update(float) override;
};


#endif //PROJEKT_BALL_HPP
