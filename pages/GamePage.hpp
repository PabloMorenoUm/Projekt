//
// Created by Pablo Moreno Um on 28.07.21.
//

#ifndef PROJEKT_GAMEPAGE_HPP
#define PROJEKT_GAMEPAGE_HPP

#include "BasicPage.hpp"

class GamePage: public BasicPage {
protected:
    const unsigned scoreLimit = 15;
    unsigned score = 0;
    Words hud{writeScore(), 200, m_WindowSize.getX() / 4, m_WindowSize.getY() / 10};
    Words hintEngine{"Press [Escape] to get back to Bob's page", 50,
                     m_WindowSize.getX() * 7 / 11, m_WindowSize.getY() / 40};
    virtual std::string writeScore() const;
};


#endif //PROJEKT_GAMEPAGE_HPP
