#include "orc.h"


void Orc::handleCollision(Player& player)
{
	player.handleCollision(*this);
}