#include "Gift_2.h"


void Gift_2::handleCollision(Player& player, vector<unique_ptr<Dwarf>>& dwarves)
{
	std::erase_if(dwarves, [](const auto& currDwarf) {return true; });

	//dwarves.clear();
}