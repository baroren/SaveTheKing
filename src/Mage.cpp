#include "Mage.h"

#include <iostream>
#include "Wall.h"

using std::cout;
using std::endl;

void Mage::handleCollision(GameObject& gameObject, const sf::Vector2f moveDirection)
{
	gameObject.handleCollision(*this, moveDirection);
}

//	collision with wall
void Mage::handleCollision(Wall& wall, const sf::Vector2f moveDirection)
{
    cout << "i am a mage, i collided with wall" << endl;
    this->m_sprite.move(sf::Vector2f(moveDirection.x * -1, moveDirection.y * -1));
}

void Mage::handleCollision(Mage& mage, const sf::Vector2f moveDirection) {}

