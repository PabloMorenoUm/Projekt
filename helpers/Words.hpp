//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_WORDS_HPP
#define PROJEKT_WORDS_HPP

#include <SFML/Graphics/Text.hpp>
#include <string>

class Words {
    sf::Text m_Text;
    sf::Font m_Font;
public:
    Words(const std::string&, unsigned);
    Words(const std::string&, unsigned, float, float);
    const sf::Text &getText() const;
    void setString(const std::string&);
    void changeColor(const sf::Color&);
};


#endif //PROJEKT_WORDS_HPP
