//
// Created by Pablo Moreno Um on 08.08.21.
//

#ifndef PROJEKT_RUN_COIN_HPP
#define PROJEKT_RUN_COIN_HPP

#include <SFML/Graphics.hpp>

class Coin {

    sf::Color neutral = sf::Color::Blue;
    sf::Color hidden = sf::Color::Transparent;
    sf::Color player = sf::Color::Red;
    sf::Color opponent = sf::Color::Yellow;
    sf::CircleShape shape;

public:
    const sf::CircleShape &getShape() const;

    bool isNeutral();
    bool isHidden();
    bool isPlayer();
    bool isOpponent();

    void makeNeutral();
    void makeHidden();
    void makePlayer();
    void makeOpponent();

    void setPosition(const float &posX, const float &posY);
    void setRadius(const float &radius);

    // Zwei Münzen sind gleich, wenn sie dieselbe Farbe haben:
    bool operator==(const Coin &rhs) const;
    bool operator!=(const Coin &rhs) const;
};


#endif //PROJEKT_RUN_COIN_HPP
