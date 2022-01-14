#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

class Resources {
public:
    static Resources &instance();

    Resources(const Resources &) = delete;

    void operator=(const Resources &) = delete;

    sf::Texture &getTexture(int i) const;

    sf::Font& getFont() const;

    //Animation *getAnimation(int i) const;

private:
    Resources();
    void buildTexture();

    sf::Texture m_temp;
    vector <sf::Sprite> m_sprite;
    vector <sf::Texture> m_texture;
    vector <string> m_imagePath = {"King.png"};
    //vector<Animation *> m_animation;
    vector<int> numOfAnim{2};
    , numOfFrames{ 4 };
    sf::Font m_font;
};