#include "Wall.h"

#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;


//	collision with a moving object
void Wall::handleCollision(Moving& moving, const sf::Vector2f moveDirection)
{
	cout << "i am wall, a moving object collided with me" << endl;

//	moving.getSprite().move(sf::Vector2f(moveDirection.x * -1, moveDirection.y * -1));

	sf::Vector2f newPos(moving.getLocation().x - moveDirection.x, moving.getLocation().y - moveDirection.y);

	moving.setLocation(newPos);
}

//	wall cannot collide with wall so do nothing
//void Wall::handleCollision(Wall& wall, const sf::Vector2f moveDirection) {}