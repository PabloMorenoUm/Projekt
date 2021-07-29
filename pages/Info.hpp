//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_INFO_HPP
#define PROJEKT_INFO_HPP

#include "BasicPage.hpp"

class Info: public BasicPage {
    unsigned itemSize = 80;
    Words title{"This game is a first try designed for the c++ course at karrieretutor.\nWe do not own the rights for the images. Creators:",
                itemSize, m_WindowSize.getX() / 50, m_WindowSize.getY() / 5};
    Words eike{"Eike Sven Krebs", itemSize, m_WindowSize.getX() / 2, m_WindowSize.getY() * 2 / 5};
    Words moritz{"Moritz Becker", itemSize, m_WindowSize.getX() / 2, m_WindowSize.getY() * 3 / 5};
    Words pablo{"Pablo Moreno Um", itemSize, m_WindowSize.getX() / 2, m_WindowSize.getY() * 4 / 5};
    void input() override;
    void update(const float &dtAsSeconds) override;
    void draw() override;
public:
    Info();
};


#endif //PROJEKT_INFO_HPP
