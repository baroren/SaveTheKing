#include "Wall.h"

#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;


//	collision with mage
void Wall::handleCollision(Mage& mage, const sf::Vector2f moveDirection)
{
	cout << "i am wall, a mage collided with me" << endl;

	mage.handleCollision(*this, moveDirection);
}

//	wall cannot collide with wall so do nothing
void Wall::handleCollision(Wall& wall, const sf::Vector2f moveDirection) {}