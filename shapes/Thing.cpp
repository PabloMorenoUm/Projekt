//
// Created by Pablo Moreno Um on 22.07.21.
//

#include "Thing.hpp"

Thing::Thing() = default;

Thing::Thing(const float& posX, const float& posY, const std::string& filename) {
    setSprite(filename);
    setPosition(posX, posY);
}

void Thing::setPosition(const float &posX, const float &posY) {
    m_Position.x = posX;
    m_Position.y = posY;
    m_Sprite.setPosition(m_Position);
}

const sf::Sprite &Thing::getSprite() const {
    return m_Sprite;
}

sf::FloatRect Thing::getBounds() const {
    return m_Sprite.getGlobalBounds();
}
