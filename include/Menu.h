#pragma once

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Window.h"
#include <string>
#include <iostream>
class Menu {
public:
        Menu();
        void createButton(string ,int x,int y);
        int handleClick(const sf::Vector2f position,sf::RenderWindow& window);
        Button* getButton(int i);
        sf::Sprite getHelp();
    void  updateBt(sf::RenderWindow& window);
    void setHelp(bool help);

        bool startGame(int i,sf::Vector2f mousePos,sf::RenderWindow& window);
        bool helpBt(int i,sf::Vector2f mousePos,sf::RenderWindow& window);
        bool quitBt(int i,sf::Vector2f mousePos,sf::RenderWindow& window);
        bool helpPressed();
private:
    vector <Button*> m_buttons;
    sf::Texture m_helpTex;
    sf:: Font m_font;
    bool m_helpPressed;
    sf:: Sprite m_help ; //need to make vector
};