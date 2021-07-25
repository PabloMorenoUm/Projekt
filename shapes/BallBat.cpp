//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "BallBat.hpp"

sf::FloatRect BallBat::getPosition() {
    return shape.getGlobalBounds();
}

const sf::RectangleShape &BallBat::getShape() const {
    return shape;
}
