//
// Created by Pablo Moreno Um on 08.08.21.
//

#ifndef PROJEKT_RUN_COIN_HPP
#define PROJEKT_RUN_COIN_HPP

#include <SFML/Graphics.hpp>

class Coin {
    static constexpr unsigned nrows = 6, ncols = 7;
    sf::Color neutralColor = sf::Color::Blue;
    sf::Color hiddenColor = sf::Color::Transparent;
    sf::Color playerColor = sf::Color::Red;
    sf::Color opponentColor = sf::Color::Yellow;
    sf::CircleShape shape;

public:
    const sf::Color &getNeutralColor() const;

    const sf::Color &getHiddenColor() const;

    const sf::Color &getPlayerColor() const;

    const sf::Color &getOpponentColor() const;

    const sf::CircleShape &getShape() const;
    void changeColor(const sf::Color &color);
    void makeNeutral();
    void makeHidden();
    void makePlayer();
    void makeOpponent();
    void setPosition(const float &posX, const float &posY);
    void setRadius(const float &radius);
};


#endif //PROJEKT_RUN_COIN_HPP
