#include "GameObject.h"

class Moving : public GameObject {
public:
using GameObject::GameObject;
	bool checkBorder();

	void move();

private:

	void movingBehavior();

};