#include "GameObject.h"

class Moving : public GameObject {
public:

	bool checkBorder();

	void move();

private:

	void movingBehavior();

};