#pragma once

#include "Moving.h"
#include "Static.h"

class Teleporter;

class Player : public Moving {
public:

    using Moving::Moving;
    void handleCollision(Teleporter& teleport);
    virtual void handleCollision(Player& player)override {};
    virtual void handleCollision(Dwarf& Dwarf)override {};
    virtual void handleCollision(Mage& mage) override {};


    virtual void handleCollision(Static& staticObject) override;

private:


};