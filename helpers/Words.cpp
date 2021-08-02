//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "Words.hpp"
#include <iostream>
using namespace std;
using namespace sf;

Words::Words(const string &text, const unsigned &size) {
    try{
        m_Font.loadFromFile("ds_digital/DS-DIGIT.ttf");
        m_Text.setFont(m_Font);
        m_Text.setCharacterSize(size);
        m_Text.setFillColor(Color::White);
        m_Text.setString(text);
    } catch (exception const& e) {
        cerr << e.what() << endl;
    }
}

Words::Words(const string &text, const unsigned &size, const float &posX, const float &posY):
        Words(text, size) {
    m_Text.setPosition(posX, posY);
}

const Text &Words::getText() const {
    return m_Text;
}

void Words::setString(const std::string &name) {
    m_Text.setString(name);
}

void Words::changeColor(const sf::Color& color) {
    m_Text.setFillColor(color);
}