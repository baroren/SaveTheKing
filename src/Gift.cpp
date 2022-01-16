#include "Gift.h"

#include <math.h>


void Gift::handleCollision(Player& player, vector<unique_ptr<Dwarf>>& dwarves)
{
	std::erase_if(dwarves, [](const auto& currDwarf) {return true;});
}

void Gift::handleCollision(Player& player, float deltaTime)
{

	int rounded = round(deltaTime);

	if (rounded % 2 == 0)
	{
		//	add time
	}

	else
	{
		//	reduce time
	}

}
