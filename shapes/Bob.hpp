//
// Created by Pablo Moreno Um on 19.07.21.
//

#ifndef PROJEKT_BOB_HPP
#define PROJEKT_BOB_HPP

#pragma once

#include "Thing.hpp"
#include "../helpers/Direction.hpp"

class Bob : public Thing {
    Direction m_RightPressed{};
    Direction m_LeftPressed{};
    Direction m_UpPressed{};
    Direction m_DownPressed{};
    float m_Speed;
public:
    Bob();
    void input();
    void update(const float &elapsedTime);
};


#endif //PROJEKT_BOB_HPP
