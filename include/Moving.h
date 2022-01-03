#pragma once
#include "GameObject.h"

class Moving : public GameObject {
public:
using GameObject::GameObject;
	bool checkBorder();


private:

	void movingBehavior();

};