//
// Created by Pablo Moreno Um on 28.07.21.
//

#include "GamePage.hpp"
#include <sstream>

std::string GamePage::writeScore() const {
    std::stringstream ss;
    if (score == scoreLimit) {
        ss << "Congratulations!\nYou just reached " << score << " points.";
    } else{
        ss << "Try to reach " << scoreLimit << " points.\nScore:" << score;
    }
    return ss.str();
}
