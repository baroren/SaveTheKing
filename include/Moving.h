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

//		moves the object in a direction using direction, deltaTime 
	void move(const Direction dir, float);

//		handle the collision of all moving objects with all objects
//	void handleCollision(Dwarf& dwarf, const sf::Vector2f moveDirection);


	virtual void handleCollision(Static& staticObject) = 0;
	virtual void handleCollision(Mage& mage) override {};

	sf::Vector2f getMoveDirection() const;
	void setMoveDirection(const sf::Vector2f newDirection);


protected:
	sf::Vector2f m_moveDirection;


private:
//		true - faces right, false - faces left
	bool m_isFacedRight;



//		returns current direction the object is facing
	bool getDirection() const;

	void movingBehavior();

};