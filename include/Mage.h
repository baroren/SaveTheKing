#pragma once

#include "Player.h"

class Mage : public Player {
public:
    using Player::Player;

    virtual void handleCollision(Fire& fire) override;
    virtual void handleCollision(Orc& orc) override;
    virtual void handleCollision(Gate& gate) override;
    virtual void handleCollision(Key& key) override {};




private:
//string m_imagePath="W_Red_Idle_SPR.png";


};