//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_DIRECTION_HPP
#define PROJEKT_DIRECTION_HPP


class Direction {
    bool m_Pressed;
    void move();
    void stop();
public:
    void handleMoving(const bool& button);
    bool isPressed() const;
};


#endif //PROJEKT_DIRECTION_HPP
