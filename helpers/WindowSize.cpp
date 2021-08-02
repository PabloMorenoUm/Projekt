//
// Created by Pablo Moreno Um on 22.07.21.
//

#include "WindowSize.hpp"

WindowSize::WindowSize() {
    // 2880
    x = (float) sf::VideoMode::getDesktopMode().width;
    // 1800
    y = (float) sf::VideoMode::getDesktopMode().height;
}

const float& WindowSize::getX() const {
    return x;
}

const float& WindowSize::getY() const {
    return y;
}
