//
// Created by Pablo Moreno Um on 08.08.21.
//

#ifndef PROJEKT_RUN_COIN_HPP
#define PROJEKT_RUN_COIN_HPP

#include <SFML/Graphics.hpp>

class Coin {
    sf::CircleShape shape;
    unsigned id;

public:
    const sf::CircleShape &getShape() const;
    unsigned int getId() const;
    void setId(const unsigned int &id);
    void changeColor(const sf::Color &color);
    void setPosition(const float &posX, const float &posY);
    void setRadius(const float &radius);
};


#endif //PROJEKT_RUN_COIN_HPP
