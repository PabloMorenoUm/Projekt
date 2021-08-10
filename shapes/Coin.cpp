//
// Created by Pablo Moreno Um on 08.08.21.
//

#include "Coin.hpp"

const sf::Color &Coin::getNeutralColor() const {
    return neutralColor;
}

const sf::Color &Coin::getHiddenColor() const {
    return hiddenColor;
}

const sf::Color &Coin::getPlayerColor() const {
    return playerColor;
}

const sf::Color &Coin::getOpponentColor() const {
    return opponentColor;
}

const sf::CircleShape &Coin::getShape() const {
    return shape;
}

void Coin::setPosition(const float &posX, const float &posY) {
    shape.setPosition(posX, posY);
}

void Coin::setRadius(const float &radius) {
    shape.setRadius(radius);
}

void Coin::makeNeutral() {
    shape.setFillColor(neutralColor);
}

void Coin::makeHidden() {
    shape.setFillColor(hiddenColor);
}

void Coin::makePlayer() {
    shape.setFillColor(playerColor);
}

void Coin::makeOpponent() {
    shape.setFillColor(opponentColor);
}

bool Coin::operator==(const sf::Color &color) const {
    return shape.getFillColor() == color;
}

bool Coin::operator!=(const sf::Color &color) const {
    return !(*this == color);
}

bool Coin::operator==(const Coin &rhs) const {
    return shape.getFillColor() == rhs.shape.getFillColor();
}

bool Coin::operator!=(const Coin &rhs) const {
    return !(rhs == *this);
}
