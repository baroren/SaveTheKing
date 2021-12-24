#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"
class MainMenu {
    public:
    MainMenu();
    //add dest
    void run();
private :
    void makeTitle(sf::Text&,int size,std::string text);

    Button* m_startGameButton;
    Button* m_helpButton;
    sf:: Font m_font;
    sf::Text m_title;
    sf::Text m_second_title;
    sf::Texture m_skelTex;
    sf::Sprite m_skeleton;
};