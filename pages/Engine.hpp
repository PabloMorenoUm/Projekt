//
// Created by Pablo Moreno Um on 19.07.21.
//

#ifndef PROJEKT_ENGINE_HPP
#define PROJEKT_ENGINE_HPP

#include "../shapes/Bob.hpp"
#include "BasicPage.hpp"

class Engine: public BasicPage {
    Bob m_Bob;

    // Things on the court
    Thing m_ThingRight{m_WindowSize.getX() * 9 / 10, m_WindowSize.getY() / 2, "Bewerbungsfoto.jpg"};
    Thing m_ThingLeft{m_WindowSize.getX() / 10, m_WindowSize.getY() / 2, "Bewerbungsfoto.jpg"};
    Thing m_ThingUp{m_WindowSize.getX() / 2, m_WindowSize.getY() / 10, "Bewerbungsfoto.jpg"};
    Thing m_ThingDown{m_WindowSize.getX() / 2, m_WindowSize.getY() * 9 / 10, "Bewerbungsfoto.jpg"};

    void input() override;
    void update(float) override;
    void draw() override;

public:
    Engine();
};

#endif //PROJEKT_ENGINE_HPP
