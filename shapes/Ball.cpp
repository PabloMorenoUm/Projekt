//
// Created by Pablo Moreno Um on 19.07.21.
//

#include "Ball.hpp"

// This the constructor and it is called when we create an object
Ball::Ball(const float &startX, const float &startY) {
    position.x = startX;
    position.y = startY;
    speed = speedConst;
    shape.setSize(sf::Vector2f(20, 20));
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
}

void Ball::reboundSides() {
    signX = not signX;
    position.x += signX ? 2.2f : -2.2f;
}

void Ball::reboundBatOrTop() {
    signY = not signY;
    position.y += signY ? 2.2f : -2.2f;
    speed += .2;
}

void Ball::hitBottom() {
    position.y = 1;
    position.x = 500;
    speed = speedConst;
}

void Ball::update(const float &elapsedTime) {
    // Update the ball position variables
    position.y += (signY ? +1.0f : -1.0f) * speed;
    position.x += (signX ? +1.0f : -1.0f) * speed;

    // Move the ball and the bat
    shape.setPosition(position);
}