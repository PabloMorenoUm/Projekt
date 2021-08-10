//
// Created by Pablo Moreno Um on 08.08.21.
//

#include "Coin.hpp"

const sf::CircleShape &Coin::getShape() const {
    return shape;
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