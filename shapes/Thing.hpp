//
// Created by Pablo Moreno Um on 22.07.21.
//

#ifndef PROJEKT_THING_HPP
#define PROJEKT_THING_HPP

#include "../helpers/Basic.hpp"

class Thing: public Basic {
protected:
    sf::Vector2f m_Position;
    void setPosition(const float& posX, const float& posY);
public:
    Thing();
    Thing(const float &posX, const float &posY, const std::string &filename);
    const sf::Sprite &getSprite() const;
    sf::FloatRect getBounds() const;
};


#endif //PROJEKT_THING_HPP
