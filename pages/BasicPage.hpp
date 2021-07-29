//
// Created by Pablo Moreno Um on 24.07.21.
//

#ifndef PROJEKT_BASICPAGE_HPP
#define PROJEKT_BASICPAGE_HPP

#include "../helpers/Basic.hpp"
#include "../helpers/Words.hpp"
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class BasicPage: public Basic {
protected:
    std::map<std::string, bool> m_MissionsCompleted;
    sf::RenderWindow m_Window;
    sf::SoundBuffer m_Buffer;
    sf::Sound m_Song;
    Words m_NotesMusic{"Press 'm' to stop the song.\n"
                       "Press 'n' to pause the song.\n"
                       "Press 'b' to continue/restart the song.\n"
                       "Press 'k' to go to the main menu.",
                       50};
    void modifySong();
    void loadSong(const std::string &song);
    void createWindow(const std::string &title);
    void goToMainMenu();
    void goToBob();
    virtual void input() = 0;
    virtual void update(const float &dtAsSeconds) = 0;
    virtual void draw() = 0;
public:
    void start();
};


#endif //PROJEKT_BASICPAGE_HPP
