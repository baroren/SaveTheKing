#include "Fire.h"


void Fire::handleCollision(Player& player) 
{
	player.handleCollision(*this);
}