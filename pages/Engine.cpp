//
// Created by Pablo Moreno Um on 19.07.21.
//

#include "Engine.hpp"
#include "Pong.hpp"
using namespace sf;

Engine::Engine() {
    setWindow("Simple Game Engine");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by upklyak - www.freepik.com</a>
    setSprite("space-game-background-neon-night-alien-landscape/1624.jpg");
    setSong("2020_09_13_rockfunk.ogg");
}

void Engine::input() {
    m_Bob.input();
}

void Engine::update(float dtAsSeconds) {
    m_Bob.update(dtAsSeconds);

    if (m_Bob.getBounds().intersects(m_ThingUp.getBounds())){
        m_Song.stop();
        m_Window.close();
        Pong pong;
        pong.start();
    }
}

void Engine::draw() {
    // Rub out the last frame
    m_Window.clear(sf::Color::White);

    // Draw the background
    m_Window.draw(m_Sprite);
    m_Window.draw(m_Bob.getSprite());
    m_Window.draw(m_ThingUp.getSprite());
    m_Window.draw(m_ThingLeft.getSprite());
    m_Window.draw(m_ThingRight.getSprite());
    m_Window.draw(m_ThingDown.getSprite());

    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}