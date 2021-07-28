//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "BasicPage.hpp"
#include "MainMenu.hpp"
#include "Engine.hpp"
#include <iostream>
using namespace sf;
using namespace std;

void BasicPage::modifySong() {
    if (Keyboard::isKeyPressed(Keyboard::M) && m_Song.getStatus() != SoundSource::Stopped)
        m_Song.stop();
    if (Keyboard::isKeyPressed(Keyboard::N) && m_Song.getStatus() != SoundSource::Paused)
        m_Song.pause();
    if (Keyboard::isKeyPressed(Keyboard::B) && m_Song.getStatus() != SoundSource::Playing)
        m_Song.play();
}

void BasicPage::loadSong(const string& song) {
    try{
        m_Buffer.loadFromFile(song);
        m_Song.setBuffer(m_Buffer);
        m_Song.setLoop(true);
        m_Song.play();
    } catch (exception const& e) {
        cerr << e.what() << endl;
    }
}

void BasicPage::createWindow(const string& title) {
    m_Window.create(VideoMode(m_WindowSize.getX(), m_WindowSize.getY()),
                    title,
                    Style::Fullscreen);
}

void BasicPage::goToMainMenu() {
    if (Keyboard::isKeyPressed(Keyboard::K)) {
        m_Song.stop();
        m_Window.close();
        MainMenu mainMenu;
        mainMenu.start();
    }
}

void BasicPage::goToBob() {
        m_Song.stop();
        m_Window.close();
        Engine engine{m_MissionsCompleted};
        engine.start();
}

void BasicPage::start() {
    Clock clock;

    while (m_Window.isOpen()) {
        Event event;
        while (m_Window.pollEvent(event)) {
            if (event.type == Event::Closed)
                m_Window.close();
        }
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        goToMainMenu();
        modifySong();
        input();
        update(dtAsSeconds);
        draw();
    }
}
