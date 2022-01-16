#pragma once

#include "Player.h"
#include "Orc.h"

class Warrior : public Player {
public:

	using Player::Player;


	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Orc& orc) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Throne& throne) override {};
	virtual void handleCollision(Key& key) override {};



private:


};