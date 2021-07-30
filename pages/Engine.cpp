//
// Created by Pablo Moreno Um on 19.07.21.
//

#include "Engine.hpp"
#include "Pong.hpp"
#include "Reaction.hpp"
#include <algorithm>
#include <utility>

using namespace sf;

Engine::Engine() {
    m_MissionsCompleted[Games::PONG] = false;
    m_MissionsCompleted[Games::GAME3] = false;
    m_MissionsCompleted[Games::REACTION] = false;
    m_MissionsCompleted[Games::GAME4] = false;
    createWindow("Simple Game Engine");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by upklyak - www.freepik.com</a>
    setSprite("abstract-grunge-decorative-relief-navy-blue-stucco-wall-texture-wide-angle-rough-colored-background.jpg");
    loadSong("2020_09_13_rockfunk.ogg");
}

Engine::Engine(std::map<Games, bool> &missionsCompleted) : Engine() {
    m_MissionsCompleted = std::move(missionsCompleted);

    m_ThingUp.setSprite(m_MissionsCompleted[Games::PONG] ? "icons8-checkmark-480.png" : "haus.png");
    m_ThingDown.setSprite(m_MissionsCompleted[Games::GAME3] ? "icons8-checkmark-480.png" : "haus.png");
    m_ThingLeft.setSprite(m_MissionsCompleted[Games::REACTION] ? "icons8-checkmark-480.png" : "haus.png");
    m_ThingRight.setSprite(m_MissionsCompleted[Games::GAME4] ? "icons8-checkmark-480.png" : "haus.png");

    if (std::all_of(m_MissionsCompleted.begin(), m_MissionsCompleted.end(),
                    [](const auto &p) { return p.second; }))
        m_Succeed.setString("All levels\nsucceeded!");
}

void Engine::input() {
    m_Bob.input();
}

void Engine::update(const float &dtAsSeconds) {
    m_Bob.update(dtAsSeconds);

    if (m_Bob.getBounds().intersects(m_ThingUp.getBounds())) {
        m_Song.stop();
        m_Window.close();
        Pong pong{m_MissionsCompleted};
        pong.start();
    }

    if (m_Bob.getBounds().intersects(m_ThingLeft.getBounds())) {
        m_Song.stop();
        m_Window.close();
        Reaction reaction{m_MissionsCompleted};
        reaction.start();
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

    m_Window.draw(m_Succeed.getText());
    m_Window.draw(m_NotesMusic.getText());
    m_Window.display();
}