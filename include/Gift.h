#pragma once

#include <memory>

#include "Static.h"
#include "Dwarf.h"

using std::unique_ptr;

class Gift : public Static {

public:

	using Static::Static;


	void handleCollision(Player& player, vector<unique_ptr<Dwarf>>&);
	void handleCollision(Player& player, float deltaTime);

	virtual void handleCollision(Dwarf& dwarf)override {};

	virtual void handleCollision(Mage& mage) override {};

private:


};