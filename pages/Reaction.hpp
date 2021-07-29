//
// Created by Pablo Moreno Um on 28.07.21.
//

#ifndef PROJEKT_REACTION_HPP
#define PROJEKT_REACTION_HPP

#include "GamePage.hpp"
#include "../helpers/Direction.hpp"

class Reaction: public GamePage {
    Words m_Q{"Q", 400, m_WindowSize.getX() / 4, m_WindowSize.getY() / 3};
    Words m_W{"W", 400, m_WindowSize.getX() / 2, m_WindowSize.getY() / 3};
    Words m_E{"E", 400, m_WindowSize.getX() * 3 / 4, m_WindowSize.getY() / 3};
    Words m_A{"A", 400, m_WindowSize.getX() / 4, m_WindowSize.getY() / 2};
    Words m_S{"S", 400, m_WindowSize.getX() / 2, m_WindowSize.getY() / 2};
    Words m_D{"D", 400, m_WindowSize.getX() * 3 / 4, m_WindowSize.getY() / 2};
    Words m_Y{"Y", 400, m_WindowSize.getX() / 4, m_WindowSize.getY() * 2 / 3};
    Words m_X{"X", 400, m_WindowSize.getX() / 2, m_WindowSize.getY() * 2 / 3};
    Words m_C{"C", 400, m_WindowSize.getX() * 3 / 4, m_WindowSize.getY() * 2 / 3};
    Direction m_PressedQ{};
    Direction m_PressedW{};
    Direction m_PressedE{};
    Direction m_PressedA{};
    Direction m_PressedS{};
    Direction m_PressedD{};
    Direction m_PressedY{};
    Direction m_PressedX{};
    Direction m_PressedC{};
    void input() override;
    void update(const float &dtAsSeconds) override;
    void draw() override;
public:
    explicit Reaction(std::map<std::string, bool> &missionsCompleted);
};


#endif //PROJEKT_REACTION_HPP
