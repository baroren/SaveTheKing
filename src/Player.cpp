#include "Player.h"

#include "Teleporter.h"

#include <iostream>

using std::cout;
using std::endl;

void Player::handleCollision(Teleporter& teleporter)
{
	cout << "teleporter" << endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		sf::Vector2f newPosition = teleporter.getLinkdedTeleporter()->getLocation();

		this->setLocation(newPosition);
	}
}

