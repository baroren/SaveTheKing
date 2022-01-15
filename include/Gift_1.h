#pragma once

#include "Gift.h"


class Gift_1 : public Gift {

public:

	using Gift::Gift;


	virtual void handleCollision(Player& player) = 0;
	virtual void handleCollision(Dwarf& dwarf)override {};

	virtual void handleCollision(Mage& mage) override {};

private:


};