//
// Created by Pablo Moreno Um on 24.07.21.
//

#include "Basic.hpp"
#include <iostream>
using namespace std;

void Basic::setSprite(const string &filename) {
    try{
        m_Texture.loadFromFile(filename);
        m_Sprite.setTexture(m_Texture);
    } catch (exception const& e) {
        cerr << e.what() << endl;
    }
}