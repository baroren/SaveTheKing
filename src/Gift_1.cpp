#include "Gift_1.h"

#include <math.h>


void Gift_1::handleCollision(Player& player, Clock& clock)
{

	int roundedTime = round(clock.getTime());

	if (roundedTime % 2 == 0)
	{
		//	add time
		clock.addTime();
	}

	else
	{
		//	reduce time
		clock.subTime();
	}

}
