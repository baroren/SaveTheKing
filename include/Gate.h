#pragma once

#include "Static.h"
#include "Player.h"

class Gate : public Static {
public:

	using Static::Static;


	virtual void handleCollision(Player& player)override;
	virtual void handleCollision(Dwarf& dwarf)override {};


private:

};