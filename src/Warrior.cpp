#include "Warrior.h"

void Warrior::handleCollision(Fire& fire)
{
    Player::stayInPlace();
}

void Warrior::handleCollision(Gate& gate)
{
    Player::stayInPlace();
}

void Warrior::handleCollision(Orc& orc)
{
    cout << "i collided with orc" << endl;
    orc.setDelete();
}