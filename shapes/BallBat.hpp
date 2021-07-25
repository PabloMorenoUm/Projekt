//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_BALLBAT_HPP
#define PROJEKT_BALLBAT_HPP

#include <SFML/Graphics.hpp>

class BallBat {
protected:
    sf::Vector2f position;
    sf::RectangleShape shape;
    float speed;
public:
    sf::FloatRect getPosition();
    const sf::RectangleShape &getShape() const;
    virtual void update(float) = 0;
};


#endif //PROJEKT_BALLBAT_HPP
