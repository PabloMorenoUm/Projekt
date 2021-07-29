//
// Created by Pablo Moreno Um on 19.07.21.
//

#ifndef PROJEKT_ENGINE_HPP
#define PROJEKT_ENGINE_HPP

#include "../shapes/Bob.hpp"
#include "BasicPage.hpp"

class Engine: public BasicPage {
    Words m_Succeed{"", 100, m_WindowSize.getX() * 2 / 3, m_WindowSize.getY() / 6};
    Bob m_Bob;

    // Things on the court
    // <div>Icons erstellt von <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/de/" title="Flaticon">www.flaticon.com</a></div>
    Thing m_ThingRight{m_WindowSize.getX() * 7 / 10, m_WindowSize.getY() * 2 / 5,
                       "haus.png"};
    Thing m_ThingLeft{m_WindowSize.getX() / 10, m_WindowSize.getY() * 2 / 5,
                      "haus.png"};
    Thing m_ThingUp{m_WindowSize.getX() * 3 / 7, m_WindowSize.getY() / 10,
                    "haus.png"};
    Thing m_ThingDown{m_WindowSize.getX() * 3 / 7, m_WindowSize.getY() * 7 / 10,
                      "haus.png"};

    void input() override;
    void update(float dtAsSeconds) override;
    void draw() override;

public:
    Engine();
    explicit Engine(std::map<std::string, bool> missionsCompleted);
};

#endif //PROJEKT_ENGINE_HPP
