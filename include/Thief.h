#pragma once

#include "Player.h"

class Thief : public Player {
public:

	using Player::Player;


	virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) override {};
    bool hasKey();

private:
bool m_haveKey;


};