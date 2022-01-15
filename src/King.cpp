#include "King.h"


void King::handleCollision(Fire& fire)
{
    Player::stayInPlace();
}

void King::handleCollision(Gate& gate)
{
    Player::stayInPlace();
}

void King::handleCollision(Orc& orc)
{
    Player::stayInPlace();
}

