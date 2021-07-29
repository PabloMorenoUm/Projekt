//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_BASIC_HPP
#define PROJEKT_BASIC_HPP

#include "WindowSize.hpp"
#include <string>

class Basic {
protected:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    WindowSize m_WindowSize;
public:
    void setSprite(const std::string &filename);
};


#endif //PROJEKT_BASIC_HPP
