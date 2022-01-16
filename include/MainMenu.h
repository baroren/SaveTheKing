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
    //add dest
    void run(sf::RenderWindow & window);
   //void printHelp(sf::RenderWindow & window,Button *button);
   void changeText(string );


private :

    sf::Text makeTitle(int size,std::string text,float,float);
    sf::Sprite testSprite;
    sf::Texture testTexture;
    vector <unique_ptr <GameObject> >m_gameObjects;
    vector <unique_ptr <Moving> >m_dwarves;
  //  vector <Button*> m_buttons;
    Menu m_menu;
    sf::Music m_music;
//  check to see if gameObject works with unique ptr and how to solve Button
//    vector <unique_ptr<GameObject>> m_gameObjects;
//    vector <unique_ptr<Button>> m_buttons;

/*    Button* m_startGameButton;
    Button* m_helpButton;
    Button * m_quit;// need to make arr*/
    sf:: Font m_font;

    vector <sf::Text> m_titles;
 /*   sf::Text m_title;
    sf::Text m_second_title;
*/
 //   sf::Texture m_helpTex;

//    sf:: Sprite m_help ; //need to make vector

};