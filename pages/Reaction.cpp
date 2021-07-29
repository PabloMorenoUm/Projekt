//
// Created by Pablo Moreno Um on 28.07.21.
//

#include "Reaction.hpp"
#include <random>

#define TYPE(LETTER) \
    m_Pressed##LETTER.handleMoving(Keyboard::isKeyPressed(Keyboard::LETTER));
#define CHANGECOLOR(LETTER) \
if (m_Pressed##LETTER.isPressed()){ \
    if (m_##LETTER.getText().getFillColor() == Color::Green) \
        ++score; \
    if (m_##LETTER.getText().getFillColor() == Color::Red && score > 0) \
        --score; \
}
#define COLOR(LETTER) \
    if (rand01(gen)) \
        m_##LETTER.changeColor(Color::Green); \
    else \
        m_##LETTER.changeColor(Color::Red);
using namespace sf;
using namespace std;

Reaction::Reaction(map<string, bool> &missionsCompleted) {
    m_MissionsCompleted = move(missionsCompleted);
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

    CHANGECOLOR(Q)
    CHANGECOLOR(W)
    CHANGECOLOR(E)
    CHANGECOLOR(A)
    CHANGECOLOR(S)
    CHANGECOLOR(D)
    CHANGECOLOR(Y)
    CHANGECOLOR(X)
    CHANGECOLOR(C)

    float timeLeft = m_Clock.getElapsedTime().asSeconds();
    auto timeFloor = (unsigned) floor(timeLeft);
    auto timeFloorBefore = (unsigned) floor(timeLeft - dtAsSeconds);

    if (0 == timeFloor % 3 & 2 == timeFloorBefore % 3){
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<> randNumb(1, 9);
        uniform_int_distribution<> rand01(0, 1);

        switch (randNumb(gen)) {
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

    if (1 == timeFloor % 3 & 0 == timeFloorBefore % 3){
        m_Q.changeColor(Color::White);
        m_W.changeColor(Color::White);
        m_E.changeColor(Color::White);
        m_A.changeColor(Color::White);
        m_S.changeColor(Color::White);
        m_D.changeColor(Color::White);
        m_Y.changeColor(Color::White);
        m_X.changeColor(Color::White);
        m_C.changeColor(Color::White);
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
