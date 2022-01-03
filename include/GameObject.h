#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"
using std::string;

enum direction { left, right, up, down };

class GameObject {
public:


    GameObject(const int x=0,const int y=0,
               const int numOfAnim=0,const int numOfFrames=0,
               const float animTime=0.17,const  float scale=0,bool faceRight=false,string imagePath="");

     void updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window);
     void  setLocation(const float x, const float y );
     sf::Vector2<float> getLocation() const;
     void move(const direction dir,float);
     sf::Sprite getSprite();
     bool getDirection()const;

private:
//      move the object on board in the appropriate direction

    bool m_isFacedRight;
    int m_row;
    string m_imagePath;
    Animation* m_animation;
	sf::Vector2i m_location;
    sf::Texture m_texture;
    sf::Sprite m_sprite;


};
