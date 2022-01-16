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

void King::handleCollision(Throne& throne)
{
    // level won woohoo
    m_levelPassed = true;

    cout << "coillided with throne" << endl;
}
