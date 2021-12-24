#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "SFML/Audio.hpp"
enum buttonState{BTN_IDLE=0,BTN_PRESSED,BTN_HOVER};
class Button
{

public:
    Button(float x, float y ,float width ,float height,sf::Font* font,std::string text,
           sf::Color idleColor,sf::Color hoverColor,sf::Color activeColor );
    sf::RectangleShape render ();
    sf::Text drawText ();
    void update (sf::Vector2f mousePos);

    //Accessors
    const bool isPressed() const;

private:
   buttonState m_bState ;
    sf::Color m_idleColor;
    sf::Color m_hoverColor;
    sf::Color m_activeColor;

    sf::RectangleShape m_shape;
    sf::Font * m_font;
    sf::Text m_button_text;
};