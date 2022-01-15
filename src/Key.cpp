#include "Key.h"


void Key::handleCollision(Player& player)
{
	player.handleCollision(*this);
}