//
// Created by Pablo Moreno Um on 08.08.21.
//

#include "Coin.hpp"

const sf::CircleShape &Coin::getShape() const {
    return shape;
}

unsigned int Coin::getId() const {
    return id;
}

void Coin::setId(const unsigned int &id) {
    Coin::id = id;
}

void Coin::changeColor(const sf::Color &color) {
    shape.setFillColor(color);
}

void Coin::setPosition(const float &posX, const float &posY) {
    shape.setPosition(posX, posY);
}

void Coin::setRadius(const float &radius) {
    shape.setRadius(radius);
}