#pragma once

#include "Player.h"

class Mage : public Player {
public:
    using Player::Player;


	virtual void handleCollision(Moving& moving, const sf::Vector2f moveDirection)override {};
	virtual void handleCollision(GameObject& gameobject) override {};

	virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) override {};




private:
//string m_imagePath="W_Red_Idle_SPR.png";


};