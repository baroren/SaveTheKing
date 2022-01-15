#include "Thief.h"


void Thief::handleCollision(Fire& fire)
{
    Player::stayInPlace();
}

void Thief::handleCollision(Gate& gate)
{
    if (m_haveKey)
    {
        gate.setDelete();
        m_haveKey = false;
    }

    else
        Player::stayInPlace();
}

void Thief::handleCollision(Orc& orc)
{
    Player::stayInPlace();
}

void Thief::handleCollision(Key& key)
{
    key.setDelete();
    m_haveKey = true;
}