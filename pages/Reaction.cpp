//
// Created by Pablo Moreno Um on 28.07.21.
//

#include "Reaction.hpp"

Reaction::Reaction(std::map<std::string, bool> missionsCompleted) {
    m_MissionsCompleted = std::move(missionsCompleted);
    createWindow("Reaktionsspiel");
    // <a href='https://www.freepik.com/vectors/background'>Background vector created by upklyak - www.freepik.com</a>
    setSprite("space-game-background-neon-night-alien-landscape/1624.jpg");
    loadSong("2019-12-08_hh.ogg");
}

void Reaction::input() {}

void Reaction::update(float) {}

void Reaction::draw() {}
