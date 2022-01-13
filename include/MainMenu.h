#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <memory>
#include "Button.h"
#include "Animation.h"
#include "Mage.h"
#include "Orc.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;


class MainMenu {
    public:
    MainMenu();
    //add dest
    void run(sf::RenderWindow & window);
private :

    sf::Text makeTitle(int size,std::string text,float,float);

    vector <unique_ptr <GameObject> >m_gameObjects;
    vector <Button*> m_buttons;

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
    sf::Texture m_helpTex;

    sf:: Sprite m_help ; //need to make vector

};