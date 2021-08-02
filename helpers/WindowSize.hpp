//
// Created by Pablo Moreno Um on 22.07.21.
//

#ifndef PROJEKT_WINDOWSIZE_HPP
#define PROJEKT_WINDOWSIZE_HPP

#include <SFML/Graphics.hpp>

class WindowSize {
    float x, y;
public:
    WindowSize();
    [[nodiscard]] const float& getX() const;
    [[nodiscard]] const float& getY() const;
};


#endif //PROJEKT_WINDOWSIZE_HPP
