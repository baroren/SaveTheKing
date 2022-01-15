#pragma once
#include "Player.h"

class King : public Player {
public:
	using Player::Player;

	virtual void handleCollision(Fire& fire) override;


private:




};