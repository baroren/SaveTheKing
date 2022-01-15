#pragma once

#include "Player.h"

class Thief : public Player {
public:

	using Player::Player;

    bool hasKey();

private:
bool m_haveKey;


};