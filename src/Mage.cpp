#include "Mage.h"

#include <iostream>
#include "Fire.h"

using std::cout;
using std::endl;

void Mage::handleCollision(Fire& fire)
{
    fire.setDelete();
}

void Mage::handleCollision(Orc& orc)
{
    Player::stayInPlace();
}


void Mage::handleCollision(Gate& gate)
{
    Player::stayInPlace();
}