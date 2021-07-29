//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_MAINMENU_HPP
#define PROJEKT_MAINMENU_HPP

#include "BasicPage.hpp"

class MainMenu: public BasicPage {
    unsigned titleSize = 150;
    unsigned itemSize = 80;
    Words title{"Super Duper Game", titleSize, m_WindowSize.getX() / 2, m_WindowSize.getY() / 5};
    Words play{"Play (press 'p' and [enter])", itemSize, m_WindowSize.getX() / 2, m_WindowSize.getY() * 2 / 5};
    Words info{"Information (press 'i' and [enter])", itemSize, m_WindowSize.getX() / 2, m_WindowSize.getY() * 3 / 5};
    Words quit{"Quit (press 'q' and [enter])", itemSize, m_WindowSize.getX() / 2, m_WindowSize.getY() * 4 / 5};
    static void markItem(Words &toBeMarked, Words &toBeUnmarked1, Words &toBeUnmarked2);

    void input() override;
    void update(const float &dtAsSeconds) override;
    void draw() override;
public:
    MainMenu();
};


#endif //PROJEKT_MAINMENU_HPP
