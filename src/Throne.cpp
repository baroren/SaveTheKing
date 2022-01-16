#include "Throne.h"


void Throne::handleCollision(Player& player)
{
	player.handleCollision(*this);
}