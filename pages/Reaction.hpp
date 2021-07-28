//
// Created by Pablo Moreno Um on 28.07.21.
//

#ifndef PROJEKT_REACTION_HPP
#define PROJEKT_REACTION_HPP

#include "BasicPage.hpp"

class Reaction: public BasicPage {
    Words q{"Q", 200, m_WindowSize.getX() / 3, m_WindowSize.getY() / 3};
    Words w{"W", 200, m_WindowSize.getX() * 2 / 3, m_WindowSize.getY() / 3};
    Words e{"E", 200, m_WindowSize.getX(), m_WindowSize.getY() / 3};
    Words a{"A", 200, m_WindowSize.getX() / 3, m_WindowSize.getY() * 2 / 3};
    Words s{"S", 200, m_WindowSize.getX() * 2 / 3, m_WindowSize.getY() * 2 / 3};
    Words d{"D", 200, m_WindowSize.getX(), m_WindowSize.getY() * 2 / 3};
    Words y{"Y", 200, m_WindowSize.getX() / 3, m_WindowSize.getY()};
    Words x{"X", 200, m_WindowSize.getX() * 2 / 3, m_WindowSize.getY()};
    Words c{"C", 200, m_WindowSize.getX(), m_WindowSize.getY()};
    unsigned score = 0, index;
    void input() override;
    void update(float) override;
    void draw() override;
public:
    explicit Reaction(std::map<std::string, bool>);
};


#endif //PROJEKT_REACTION_HPP
