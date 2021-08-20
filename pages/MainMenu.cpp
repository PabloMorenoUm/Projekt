//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "MainMenu.hpp"
#include "Engine.hpp"
#include "Info.hpp"
using namespace sf;
using namespace std;

MainMenu::MainMenu() {
    createWindow("Welcome to this freaky game!!!");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by freepik - www.freepik.com</a>
    setSprite("blue-copy-space-digital-background/4882066.jpg");
    loadSong("flm.wav");
    title.changeColor(Color::Green);
}

void MainMenu::markItem(Words &toBeMarked, Words &toBeUnmarked1, Words &toBeUnmarked2) {
    toBeUnmarked1.changeColor(Color::White);
    toBeUnmarked2.changeColor(Color::White);
    toBeMarked.changeColor(Color::Yellow);
}

void MainMenu::input() {
    if (Keyboard::isKeyPressed(Keyboard::P))
        markItem(play, info, quit);
    if (Keyboard::isKeyPressed(Keyboard::I))
        markItem(info, play, quit);
    if (Keyboard::isKeyPressed(Keyboard::Q))
        markItem(quit, info, play);

    if (Keyboard::isKeyPressed(Keyboard::Enter)){
        if (play.getText().getFillColor() == Color::Yellow) {
            m_Song.stop();
            m_Window.close();
            Engine engine;
            engine.start();
        }
        if (info.getText().getFillColor() == Color::Yellow) {
            m_Song.stop();
            m_Window.close();
            Info infopage;
            infopage.start();
        }
        if (quit.getText().getFillColor() == Color::Yellow)
            m_Window.close();
    }
}

void MainMenu::update(const float &dtAsSeconds) {
}

void MainMenu::draw() {
    // Rub out the last frame
    m_Window.clear(sf::Color::White);

    // Draw the background
    m_Window.draw(m_Sprite);
    m_Window.draw(title.getText());
    m_Window.draw(play.getText());
    m_Window.draw(info.getText());
    m_Window.draw(quit.getText());

    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}