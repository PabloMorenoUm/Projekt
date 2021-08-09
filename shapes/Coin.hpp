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
    unsigned id;
    std::vector<std::vector<Coin>> spielfeld;
    bool rightCondition() const;
    bool leftCondition() const;
    bool upperCondition() const;
    bool lowerCondition() const;

public:
    const sf::Color &getNeutralColor() const;

    const sf::Color &getHiddenColor() const;

    const sf::Color &getPlayerColor() const;

    const sf::Color &getOpponentColor() const;

    unsigned getRightNeighbor() const;

    unsigned getLeftNeighbor() const;

    unsigned getUpperNeighbor() const;

    unsigned getLowerNeighbor() const;

    unsigned getRightUpperNeighbor() const;

    unsigned getRightLowerNeighbor() const;

    unsigned getLeftUpperNeighbor() const;

    unsigned getLeftLowerNeighbor() const;

    const sf::CircleShape &getShape() const;
    unsigned int getId() const;
    void setId(const unsigned int &id);
    void changeColor(const sf::Color &color);
    void makeNeutral();
    void makeHidden();
    void makePlayer();
    void makeOpponent();
    void setPosition(const float &posX, const float &posY);
    void setRadius(const float &radius);

    bool operator==(const Coin &rhs) const;

    bool operator!=(const Coin &rhs) const;
};


#endif //PROJEKT_RUN_COIN_HPP
