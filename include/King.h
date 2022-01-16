#pragma once
#include "Player.h"

class King : public Player {
public:
	using Player::Player;

	virtual void handleCollision(Fire& fire) override;
	virtual void handleCollision(Key& key) override {};
	virtual void handleCollision(Orc& orc) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Throne& throne) override;

	virtual bool getLevelPassed() const override;

private:

	bool m_levelPassed = false;


};