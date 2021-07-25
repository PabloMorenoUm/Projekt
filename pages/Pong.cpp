//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "Pong.hpp"
#include <sstream>
using namespace sf;

Pong::Pong() {
    setWindow("Pong");
    setSong("2021_04_07_Helenenmarsch.ogg");
}

std::string Pong::writeScore() const {
    std::stringstream ss;
    ss << "Score:" << score << "    Lives:" << lives;
    return ss.str();
}

void Pong::input() {
    bat.input();
}

void Pong::update(float dtAsSeconds) {
    if (ball.getPosition().top > m_WindowSize.getY()) {
        ball.hitBottom();
        lives--;

        if (lives < 1) {
            score = 0;
            lives = 3;
        }
    }

    if (ball.getPosition().top < 0) {
        ball.reboundBatOrTop();
        score++;
    }

    if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > m_WindowSize.getX())
        ball.reboundSides();

// Has the ball hit the bat?
    if (ball.getPosition().intersects(bat.getPosition()))
        ball.reboundBatOrTop();

    ball.update(dtAsSeconds);
    bat.update(dtAsSeconds);
    hud.setString(writeScore());
}

void Pong::draw() {
    m_Window.clear(Color(26, 128, 182, 255));

    m_Window.draw(bat.getShape());
    m_Window.draw(ball.getShape());

    // Draw our score
    m_Window.draw(hud.getText());

    m_Window.draw(m_NotesMusic.getText());
    // Show everything we just drew
    m_Window.display();
}