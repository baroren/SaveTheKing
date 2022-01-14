#include "Wall.h"

#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;



void Wall::handleCollision(Player& player)
{
	cout << "i am wall, a moving object collided with me" << endl;

	sf::Vector2f newPos(player.getLocation().x - player.getMoveDirection().x,
						player.getLocation().y - player.getMoveDirection().y);

	player.setLocation(newPos);
}

void Wall::handleCollision(Dwarf& dwarf)
{
	dwarf.invertMove();
}

//	wall cannot collide with wall so do nothing
//void Wall::handleCollision(Wall& wall, const sf::Vector2f moveDirection) {}