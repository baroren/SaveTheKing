#pragma once

#include "Player.h"
#include "Key.h"
#include "Gate.h"

class Thief : public Player {
public:

	using Player::Player;

	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Key& key) override;
	virtual void handleCollision(Orc& orc) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Throne& throne) override {};

private:
	bool m_haveKey = false;


};