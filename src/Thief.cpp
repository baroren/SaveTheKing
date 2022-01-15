#include "Thief.h"

bool Thief:: hasKey()
{
    return m_haveKey;
}


void Thief::handleCollision(Fire& fire)
{
    Player::stayInPlace();
}