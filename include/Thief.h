#pragma once

#include "Player.h"

class Thief : public Player {
public:

	using Player::Player;

	virtual void handleCollision(Fire& fire) override;

    bool hasKey();

private:
bool m_haveKey;


};