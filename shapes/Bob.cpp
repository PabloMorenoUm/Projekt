//
// Created by Pablo Moreno Um on 19.07.21.
//

#include "Bob.hpp"
using namespace sf;

Bob::Bob() {
    m_Speed = 1000.1f;
    setSprite("bob.png");
    setPosition(m_WindowSize.getX() / 2, m_WindowSize.getY() / 2);
}

void Bob::input() {
    m_RightPressed.handleMoving(Keyboard::isKeyPressed(Keyboard::Right));
    m_LeftPressed.handleMoving(Keyboard::isKeyPressed(Keyboard::Left));
    m_UpPressed.handleMoving(Keyboard::isKeyPressed(Keyboard::Up));
    m_DownPressed.handleMoving(Keyboard::isKeyPressed(Keyboard::Down));
}

void Bob::update(const float &elapsedTime) {
    if (m_RightPressed.isPressed())
        m_Position.x += m_Speed * elapsedTime;

    if (m_LeftPressed.isPressed())
        m_Position.x -= m_Speed * elapsedTime;

    if (m_UpPressed.isPressed())
        m_Position.y -= m_Speed * elapsedTime;

    if (m_DownPressed.isPressed())
        m_Position.y += m_Speed * elapsedTime;

    m_Sprite.setPosition(m_Position);

}