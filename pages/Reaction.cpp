//
// Created by Pablo Moreno Um on 28.07.21.
//

#include "Reaction.hpp"
#include <cstdlib>

#define TYPE(LETTER) \
if (Keyboard::isKeyPressed(Keyboard::LETTER)){ \
    if (m_##LETTER.getText().getFillColor() == Color::Green) \
        ++score; \
    if (m_##LETTER.getText().getFillColor() == Color::Red && score > 0) \
        --score; \
}
#define COLOR(LETTER) \
    if (green) \
        m_##LETTER.changeColor(Color::Green); \
    else \
        m_##LETTER.changeColor(Color::Red);
using namespace sf;

Reaction::Reaction(std::map<std::string, bool> &missionsCompleted) {
    m_MissionsCompleted = std::move(missionsCompleted);
    createWindow("Reaktionsspiel");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by upklyak - www.freepik.com</a>
    setSprite("space-game-background-neon-night-alien-landscape/1624.jpg");
    loadSong("2019-12-08_hh.ogg");
}

void Reaction::input() {
    if (Keyboard::isKeyPressed(Keyboard::Escape))
        goToBob();

    TYPE(Q)
    TYPE(W)
    TYPE(E)
    TYPE(A)
    TYPE(S)
    TYPE(D)
    TYPE(Y)
    TYPE(X)
    TYPE(C)
}

void Reaction::update(const float &dtAsSeconds) {
    if (scoreLimit == score) {
        m_MissionsCompleted["Reaction"] = true;
        goToBob();
    }

    m_Q.changeColor(Color::White);
    m_W.changeColor(Color::White);
    m_E.changeColor(Color::White);
    m_A.changeColor(Color::White);
    m_S.changeColor(Color::White);
    m_D.changeColor(Color::White);
    m_Y.changeColor(Color::White);
    m_X.changeColor(Color::White);
    m_C.changeColor(Color::White);

    index = rand() % 9 + 1;
    green = rand() % 2;

    switch (index) {
        case 1:
            COLOR(Q)
            break;
        case 2:
            COLOR(W)
            break;
        case 3:
            COLOR(E)
            break;
        case 4:
            COLOR(A)
            break;
        case 5:
            COLOR(S)
            break;
        case 6:
            COLOR(D)
            break;
        case 7:
            COLOR(Y)
            break;
        case 8:
            COLOR(X)
            break;
        case 9:
            COLOR(C)
            break;
        default:
            hud.setString("There is a mistake!!!");
    }
}

void Reaction::draw() {
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_Sprite);
    m_Window.draw(m_Q.getText());
    m_Window.draw(m_W.getText());
    m_Window.draw(m_E.getText());
    m_Window.draw(m_A.getText());
    m_Window.draw(m_S.getText());
    m_Window.draw(m_D.getText());
    m_Window.draw(m_Y.getText());
    m_Window.draw(m_X.getText());
    m_Window.draw(m_C.getText());
    m_Window.draw(hud.getText());
    m_Window.draw(hintEngine.getText());
    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}
