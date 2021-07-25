//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "Direction.hpp"

void Direction::move() {
    m_Pressed = true;
}

void Direction::stop() {
    m_Pressed = false;
}

void Direction::handleMoving(const bool& button) {
    if(button) {
        move();
    } else {
        stop();
    }
}

bool Direction::isPressed() const {
    return m_Pressed;
}
