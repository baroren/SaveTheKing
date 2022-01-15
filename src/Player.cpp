#include "Player.h"

#include "Teleporter.h"

#include <iostream>

using std::cout;
using std::endl;

void Player::handleCollision(Teleporter& teleporter)
{
	sf::Vector2f newPosition = teleporter.getLinkdedTeleporterLocation();

	this->setLocation(newPosition);
}

void Player::handleCollision(Static& staticObject)
{
	 staticObject.handleCollision(*this);
}

void Player::stayInPlace()
{
	sf::Vector2f newPos(getLocation().x - getMoveDirection().x, getLocation().y - getMoveDirection().y);

	setLocation(newPos);
}