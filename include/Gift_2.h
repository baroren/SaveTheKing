#pragma once

#include <memory>

#include "Static.h"
#include "Dwarf.h"

using std::unique_ptr;

class Gift_2 : public Static {

public:

	using Static::Static;


	void handleCollision(Player& player, vector<unique_ptr<Dwarf>>&);

	virtual void handleCollision(Player& player)override {};

	virtual void handleCollision(Dwarf& dwarf)override {};

private:


};