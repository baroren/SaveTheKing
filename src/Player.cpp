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

void Player::handleCollision(Gift_2& gift_2, vector<unique_ptr<Dwarf>>& dwarves)
{
	gift_2.handleCollision(*this, dwarves);

	gift_2.setDelete();
}

void Player::handleCollision(Gift_1& gift_1, Clock& clock)
{
	gift_1.handleCollision(*this, clock);

	gift_1.setDelete();
}