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

bool Coin::operator==(const Coin &rhs) const {
    return id == rhs.id;
}

bool Coin::operator!=(const Coin &rhs) const {
    return !(rhs == *this);
}

bool Coin::rightCondition() const {
    return id <= nrows * (ncols - 1);
}

bool Coin::leftCondition() const {
    return id > nrows;
}

bool Coin::upperCondition() const {
    return id % nrows != 1;
}

bool Coin::lowerCondition() const {
    return id % nrows != 0;
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

unsigned Coin::getRightNeighbor() const {
    if (rightCondition())
        return id + nrows;
    return -1;
}

unsigned Coin::getLeftNeighbor() const {
    if (leftCondition())
        return id - nrows;
    return -1;
}

unsigned Coin::getUpperNeighbor() const {
    if (upperCondition())
        return id - 1;
    return -1;
}

unsigned Coin::getLowerNeighbor() const {
    if (lowerCondition())
        return id + 1;
    return -1;
}

unsigned Coin::getRightUpperNeighbor() const {
    if (rightCondition() && upperCondition())
        return getUpperNeighbor() + nrows;
    return -1;
}

unsigned Coin::getRightLowerNeighbor() const {
    if (rightCondition() && lowerCondition())
        return getLowerNeighbor() + nrows;
    return -1;
}

unsigned Coin::getLeftUpperNeighbor() const {
    if (leftCondition() && upperCondition())
        return getUpperNeighbor() - nrows;
    return -1;
}

unsigned Coin::getLeftLowerNeighbor() const {
    if (leftCondition() && lowerCondition())
        return getLowerNeighbor() - nrows;
    return -1;
}