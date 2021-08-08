//
// Created by Pablo Moreno Um on 08.08.21.
//

#ifndef PROJEKT_RUN_CONNECTFOUR_HPP
#define PROJEKT_RUN_CONNECTFOUR_HPP

#include "GamePage.hpp"
#include "Coin.hpp"

class ConnectFour: public GamePage {
    sf::Color neutralColor = sf::Color::Blue;
    sf::Color hiddenColor = sf::Color::Transparent;
    sf::Color userColor = sf::Color::Red;
    sf::Color computerColor = sf::Color::Yellow;
    static constexpr unsigned nrows = 6, ncols = 7;
    Coin coins[nrows][ncols];
    Coin coinsOptions[ncols];
    Words numbers[ncols];
    void input() override;
    void update(const float &dtAsSeconds) override;
    void draw() override;
public:
    explicit ConnectFour(std::map<Games, bool> &missionsCompleted);
};


#endif //PROJEKT_RUN_CONNECTFOUR_HPP
