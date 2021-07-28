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
    Words hintEngine{"Get back to Bob's page", 50, m_WindowSize.getX() / 100, m_WindowSize.getY() * 99 / 100};
    virtual std::string writeScore() const;
};


#endif //PROJEKT_GAMEPAGE_HPP
