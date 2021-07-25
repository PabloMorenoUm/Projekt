//
// Created by Pablo Moreno Um on 22.07.21.
//

#ifndef PROJEKT_THING_HPP
#define PROJEKT_THING_HPP

#include "../helpers/Basic.hpp"

class Thing: public Basic {
protected:
    sf::Vector2f m_Position;
    void setPosition(const float&, const float&);
public:
    Thing();
    Thing(const float&, const float&, const std::string&);
    const sf::Sprite &getSprite() const;
    sf::FloatRect getBounds() const;
};


#endif //PROJEKT_THING_HPP
