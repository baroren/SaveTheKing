#pragma once

#include "Gift.h"


class Gift_2 : public Gift {

public:

	using Gift::Gift;


	virtual void handleCollision(Player& player) override;
	virtual void handleCollision(Dwarf& dwarf)override {};

	virtual void handleCollision(Mage& mage) override {};

private:


};