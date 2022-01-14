#pragma once

#include "GameObject.h"
#include "Static.h"

enum Direction { LEFT, RIGHT, UP, DOWN };

class Dwarf;
class Static;

class Moving : public GameObject {
public:

	Moving(const sf::Vector2f position, const int numOfAnim, const int numOfFrames, const float animTime,
				const float scale, const string imagePath, const bool isFacedRight);

	bool checkBorder();

//		moves the object in a direction using direction, deltaTime and saves the direction it took
	void move(const Direction dir, float, sf::Vector2f&);

//		handle the collision of all moving objects with all objects
//	void handleCollision(Dwarf& dwarf, const sf::Vector2f moveDirection);
	void handleCollision(GameObject& gameobject) override;
	void handleCollision(Static& staticObject, const sf::Vector2f moveDirection);


private:
//		true - faces right, false - faces left
	bool m_isFacedRight;

//		returns current direction the object is facing
	bool getDirection() const;

	void movingBehavior();

};