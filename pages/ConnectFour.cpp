//
// Created by Pablo Moreno Um on 08.08.21.
//

#include "ConnectFour.hpp"
#include <sstream>

#define TYPE(NUMBER) \
    if (Keyboard::isKeyPressed(Keyboard::Num##NUMBER)) { \
        int tobeChanged = NUMBER - 1; \
        coinsOptions[tobeChanged].changeColor(userColor); \
        for (int j = 0; j < ncols; ++j) { \
            if (j != tobeChanged) \
                coinsOptions[j].changeColor(hiddenColor); \
            } \
        } \
    }

using namespace sf;

ConnectFour::ConnectFour(std::map<Games, bool> &missionsCompleted) {
    unsigned id = 0;
    for (int j = 0; j < ncols; ++j) {
        // Münzen auf dem Spielfeld:
        for (int i = 0; i < nrows; ++i) {
            ++id;
            Coin &coin = coins[i][j];
            coin.setId(id);
            coin.changeColor(neutralColor);
            coin.setRadius(100);
            coin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                             m_WindowSize.getY() * ((float) i + 1.8) / (nrows + 2));
        }
        // Beschriftung ganz unten:
        std::stringstream ss;
        ss << j + 1;
        Words &number = numbers[j];
        number.setString(ss.str());
        number.setSize(70);
        number.setPosition(m_WindowSize.getX() * ((float) j + .45) / ncols,
                           m_WindowSize.getY() * 19 / 20);

        // Anzeige "Auswahlmöglichkeit Spalte" über dem Spielfeld:
        Coin &optionalCoin = coinsOptions[j];
        optionalCoin.changeColor(hiddenColor);
        optionalCoin.setRadius(100);
        optionalCoin.setPosition(m_WindowSize.getX() * ((float) j + .3) / ncols,
                                 m_WindowSize.getY() * .8 / (nrows + 2));
    }

    m_MissionsCompleted = std::move(missionsCompleted);
    createWindow("ConnectFour");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by BiZkettE1 - www.freepik.com</a>
    setSprite("abstract-banner-background-with-red-shapes/ABSTRACT_BACKGROUND_01.jpg");
    loadSong("2020-08-02.ogg");
    hud.setString("Try to align four coins.");
}

void ConnectFour::input() {
    if (Keyboard::isKeyPressed(Keyboard::Escape))
        goToBob();

    if (Keyboard::isKeyPressed(Keyboard::Num1)) {
        int tobeChanged = 0;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num2)) {
        int tobeChanged = 1;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num3)) {
        int tobeChanged = 2;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num4)) {
        int tobeChanged = 3;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num5)) {
        int tobeChanged = 4;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num6)) {
        int tobeChanged = 5;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Num7)) {
        int tobeChanged = 6;
        coinsOptions[tobeChanged].changeColor(userColor);
        for (int j = 0; j < ncols; ++j) {
            if (j != tobeChanged)
                coinsOptions[j].changeColor(hiddenColor);
        }
    }

    if(Keyboard::isKeyPressed(Keyboard::Enter)){
        for (int j = 0; j < ncols; ++j) {
            // Suche nach der markierten Spalte:
            Coin &optionalCoin = coinsOptions[j];
            if(optionalCoin.getShape().getFillColor() == userColor) {
                optionalCoin.changeColor(hiddenColor);
                // Münze einwerfen. Die soll so weit UNTEN liegen wie möglich!
                for (int i = nrows - 1; i >= 0; --i) {
                    Coin &coin = coins[i][j];
                    if (coin.getShape().getFillColor() == neutralColor) {
                        coin.changeColor(userColor);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void ConnectFour::update(const float &dtAsSeconds) {
    // Do nothing :-)
}

void ConnectFour::draw() {
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_Sprite);
    for (int j = 0; j < ncols; ++j) {
        for (auto &coinsRow : coins) {
            m_Window.draw(coinsRow[j].getShape());
        }
        m_Window.draw(numbers[j].getText());
        m_Window.draw(coinsOptions[j].getShape());
    }
    m_Window.draw(hud.getText());
    m_Window.draw(hintEngine.getText());
    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}