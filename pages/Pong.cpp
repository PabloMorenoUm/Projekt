//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "Pong.hpp"
#include "Engine.hpp"
#include <sstream>
#include <utility>
using namespace sf;

Pong::Pong(std::map<Games, bool> &missionsCompleted) {
    m_MissionsCompleted = std::move(missionsCompleted);
    createWindow("Pong");
    loadSong("2020-10-25_NotInAbleton.ogg");
}

std::string Pong::writeScore() const {
    std::stringstream ss;
    if (scoreLimit == score) {
        ss << "Congratulations!\nYou just reached " << score << " points.";
    } else{
        ss << "Try to reach " << scoreLimit << " points.\nScore:" << score << "    Lives:" << lives;
    }
    return ss.str();
}

void Pong::input() {
    bat.input();
    if (Keyboard::isKeyPressed(Keyboard::Escape))
        goToBob();
}

void Pong::update(const float &dtAsSeconds) {
    if(scoreLimit == score) {
        m_MissionsCompleted[Games::PONG] = true;
        goToBob();
    }

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

    m_Window.draw(hintEngine.getText());
    m_Window.draw(m_NotesMusic.getText());
    // Show everything we just drew
    m_Window.display();
}