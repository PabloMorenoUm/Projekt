//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "Info.hpp"

Info::Info() {
    createWindow("Information about this game");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by freepik - www.freepik.com</a>
    setSprite("halftone-background-with-circles/5172658.jpg");
    loadSong("2021_05_28_zug_ibk.ogg");
}

void Info::input() {}

void Info::update(const float &dtAsSeconds) {}

void Info::draw() {
    // Rub out the last frame
    m_Window.clear(sf::Color::White);

    // Draw the background
    m_Window.draw(m_Sprite);
    m_Window.draw(title.getText());
    m_Window.draw(eike.getText());
    m_Window.draw(moritz.getText());
    m_Window.draw(pablo.getText());

    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}