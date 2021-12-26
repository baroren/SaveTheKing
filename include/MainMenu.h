#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"
#include "GameController.h"
#include "Animation.h"
#include "Mage.h"

class MainMenu {
    public:
    MainMenu();
    //add dest
    void run();
private :

    void makeTitle(sf::Text&,int size,std::string text);
   // GameController gameController;
    Mage* mage;
    Animation *m_animation;
    Animation *m_animationSkel;
    Button* m_startGameButton;
    Button* m_helpButton;
    Button * m_quit;// need to make arr
    sf:: Font m_font;
    sf::Text m_title;
    sf::Text m_second_title;
    sf::Texture m_skelTex;
    sf::Texture m_helpTex;
    sf::Texture m_mageAnimaton;
    sf::Sprite m_mage;
    sf::Sprite m_skeleton;
    sf:: Sprite m_help ; //need to make vector

};