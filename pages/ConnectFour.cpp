//
// Created by Pablo Moreno Um on 08.08.21.
//

#include "ConnectFour.hpp"

using namespace sf;

ConnectFour::ConnectFour(std::map<Games, bool> &missionsCompleted) {
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

    board.input(hud);
}

void ConnectFour::update(const float &dtAsSeconds) {
    if (board.isPlayerWins()) {
        m_MissionsCompleted[Games::CONNECTFOUR] = true;
        goToBob();
    }
    if (board.isPlayerLoses())
        goToBob();
}

void ConnectFour::draw() {
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_Sprite);

    board.draw(m_Window);

    m_Window.draw(hud.getText());
    m_Window.draw(hintEngine.getText());
    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}