//
// Created by Pablo Moreno Um on 19.07.21.
//

#include "Bat.hpp"
using namespace sf;

// This the constructor and it is called when we create an object
Bat::Bat(float startX, float startY) {
    position.x = startX;
    position.y = startY;
    
    speed = 1800.5f;

    shape.setSize(Vector2f(250, 10));
    shape.setPosition(position);

    shape.setFillColor(Color::Cyan);
}

void Bat::moveLeft(float elapsedTime) {
    position.x -= speed * elapsedTime;
}

void Bat::moveRight(float elapsedTime) {
    position.x += speed * elapsedTime;
}

void Bat::input() {
    m_RightPressed.handleMoving(Keyboard::isKeyPressed(Keyboard::Right));
    m_LeftPressed.handleMoving(Keyboard::isKeyPressed(Keyboard::Left));
}

void Bat::update(float elapsedTime) {
    if (m_LeftPressed.isPressed() && getPosition().left > 0)
        moveLeft(elapsedTime);
    else if (m_RightPressed.isPressed() &&
             getPosition().left + getPosition().width < m_WindowSize.getX())
        moveRight(elapsedTime);

    shape.setPosition(position);
}