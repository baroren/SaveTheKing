#include "Gate.h"

void Gate::handleCollision(Player& player)
{
	player.handleCollision(*this);
}