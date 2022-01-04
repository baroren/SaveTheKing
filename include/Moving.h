#pragma once
#include "GameObject.h"

class Moving : public GameObject {
public:

	Moving(const int x, const int y, const int numOfAnim, const int numOfFrames, const float animTime, 
				const float scale, const string imagePath, const bool isFacedRight);

	bool checkBorder();

//		moves the object in a direction
	void move(const direction dir, float);



private:
//		true - faces right, false - faces left
	bool m_isFacedRight;

//		returns current direction the object is facing
	bool getDirection() const;

	void movingBehavior();

};