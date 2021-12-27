#pragma once

#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"
using std::string;

const enum direction { left, right, up, down };

class GameObject {
public:
	GameObject(const int x=0,const int y=0,
               const int numOfAnim=0,const int numOfFrames=0,
               const float animTime=0.17,const  float scale=0,string imagePath="");

     void updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window);
     void  setLocation(const float x, const float y );
     sf::Vector2<float> getLocation() const;
     void move(const direction dir, float deltaTime);

private:
//      move the object on board in the appropriate direction



    string m_imagePath;
    Animation* m_animation;
	sf::Vector2i m_location;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
