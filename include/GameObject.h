#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"


#include <iostream>

using std::cout;
using std::endl;


//#include "Resources.h"
#include "Resources.h"
#include "Macros.h"

class Mage;
class Wall;
class Moving;
class Player;
class Dwarf;

using std::string;



class GameObject {
public:


    GameObject(const sf::Vector2f position,gameObjectId id=king,float scale=0);

     void updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window);
     void setLocation(const sf::Vector2f position);
     sf::Vector2<float> getLocation() const;

     bool checkCollision(const GameObject& gameObject);

     void handleCollision(GameObject& gameobject) { cout << "unknown object" << endl; };

     virtual void handleCollision(Player& player) = 0;
     virtual void handleCollision(Dwarf& Dwarf) = 0;


     virtual void handleCollision(Mage& mage) = 0;

     sf::Sprite getSprite() const;


protected:
    sf::Sprite m_sprite;

private:
    string m_imagePath;
    Animation* m_animation;
//	sf::Vector2i m_location;
    sf::Texture m_texture;

};