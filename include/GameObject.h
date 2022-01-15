#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"
//#include "Resources.h"
#include "Resources.h"
#include "Macros.h"
class Mage;
class Wall;
class Moving;
class Player;

using std::string;



class GameObject {
public:


    GameObject(const sf::Vector2f position,gameObjectId id=king,float scale=0);

     void updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window);
     void setLocation(const sf::Vector2f position);
     sf::Vector2<float> getLocation() const;

     bool checkCollision(const GameObject& gameObject);


     virtual void handleCollision(Moving& moving, const sf::Vector2f moveDirection) = 0;
     virtual void handleCollision(GameObject& gameobject) = 0;

     virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) = 0;

     sf::Sprite getSprite() const;


protected:
    sf::Sprite m_sprite;

private:
    string m_imagePath;
    Animation* m_animation;
//	sf::Vector2i m_location;
    sf::Texture m_texture;

};