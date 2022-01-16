#pragma once

#include <memory>

#include "Static.h"
#include "Dwarf.h"
#include "Clock.h"

using std::unique_ptr;

class Gift_1 : public Static {

public:

	using Static::Static;

	void handleCollision(Player& player, Clock& clock);

	virtual void handleCollision(Dwarf& dwarf)override {};


	virtual void handleCollision(Player& player)override {};

private:


};