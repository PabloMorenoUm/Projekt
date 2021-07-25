//
// Created by Pablo Moreno Um on 22.07.21.
//

#include "WindowSize.hpp"

WindowSize::WindowSize() {
    // 2880
    x = sf::VideoMode::getDesktopMode().width;
    // 1800
    y = sf::VideoMode::getDesktopMode().height;
}

float WindowSize::getX() const {
    return x;
}

float WindowSize::getY() const {
    return y;
}
