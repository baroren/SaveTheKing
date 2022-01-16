#include "Gift_1.h"

#include <math.h>


void Gift_1::handleCollision(Player& player, Clock& clock)
{

	int roundedTime = round(clock.getTime());
	cout << roundedTime << endl;
	if (roundedTime % 2 == 0)
	{
		//	add time
		cout << "add" << endl;
		clock.addTime();
	}

	else
	{
		cout << "sub" << endl;
		//	reduce time
		clock.subTime();
	}

}
