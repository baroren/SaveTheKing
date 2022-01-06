#include "Mage.h"

#include <iostream>
#include "Wall.h"

using std::cout;
using std::endl;

void Mage::handleCollision(GameObject& gameObject, const sf::Vector2f moveDirection)
{
	gameObject.handleCollision(*this, moveDirection);
}

void Mage::handleCollision(Moving& movingObject, const sf::Vector2f moveDirection) {}

