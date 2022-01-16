#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <iostream>
#include <memory>
#include "Button.h"
#include "Animation.h"
#include "Mage.h"
#include "Orc.h"
#include "Menu.h"
#include "Resources.h"
#include "Moving.h"
using std::vector;
using std::make_unique;
using std::unique_ptr;


class MainMenu {
    public:
    MainMenu();
    void run(sf::RenderWindow & window);
   void changeText(string );


private :

    sf::Text makeTitle(int size,std::string text,float,float);
    sf::Sprite testSprite;
    sf::Texture testTexture;
    vector <unique_ptr <GameObject> >m_gameObjects;
    vector <unique_ptr <Moving> >m_dwarves;
    Menu m_menu;
    sf::Music m_music;
    sf:: Font m_font;

    vector <sf::Text> m_titles;


};