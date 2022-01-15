#pragma once

#include "Static.h"
#include "Player.h"


class Orc : public Static {
public:
	using Static::Static;


	virtual void handleCollision(Player& player) override;
	virtual void handleCollision(Dwarf& dwarf)override {};

	virtual void handleCollision(Mage& mage) override {};


private:


};