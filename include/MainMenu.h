#pragma once
#include "GameController.h"
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
    GameController gameController;


    Button* m_startGameButton;
    Button* m_helpButton;
    Button * m_quit;// need to make arr
    sf:: Font m_font;
    sf::Text m_title;
    sf::Text m_second_title;
    sf::Texture m_skelTex;
    sf::Texture m_helpTex;
    sf::Sprite m_skeleton;
    sf:: Sprite m_help ; //need to make vector
};