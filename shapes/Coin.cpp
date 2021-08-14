//
// Created by Pablo Moreno Um on 08.08.21.
//

#include "Coin.hpp"


const sf::CircleShape &Coin::getShape() const {
    return shape;
}

void Coin::setPosition(const float &posX, const float &posY) {
    shape.setPosition(posX, posY);
}

void Coin::setRadius(const float &radius) {
    shape.setRadius(radius);
}

bool Coin::isNeutral() {
    return shape.getFillColor() == neutral;
}

bool Coin::isHidden() {
    return shape.getFillColor() == hidden;
}

bool Coin::isPlayer() {
    return shape.getFillColor() == player;
}

bool Coin::isOpponent() {
    return shape.getFillColor() == opponent;
}

void Coin::makeNeutral() {
    shape.setFillColor(neutral);
}

void Coin::makeHidden() {
    shape.setFillColor(hidden);
}

void Coin::makePlayer() {
    shape.setFillColor(player);
}

void Coin::makeOpponent() {
    shape.setFillColor(opponent);
}

bool Coin::operator==(const Coin &rhs) const {
    return shape.getFillColor() == rhs.shape.getFillColor();
}

bool Coin::operator!=(const Coin &rhs) const {
    return !(rhs == *this);
}
