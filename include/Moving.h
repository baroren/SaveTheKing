#pragma once

#include "GameObject.h"
#include "Static.h"

enum Direction { LEFT, RIGHT, UP, DOWN };

class Dwarf;
class Static;

class Moving : public GameObject {
public:

	Moving(const sf::Vector2f position = sf::Vector2f(0,0), gameObjectId id = king, float scale = 0, 
			const bool isFacedRight = true, const sf::Vector2f moveDirection = sf::Vector2f(0,1));

	//  moves the moving object based on the direction received and deltaTime
	void move(const Direction dir, float);

//		handle the collision of all moving objects with all objects
//	void handleCollision(Dwarf& dwarf, const sf::Vector2f moveDirection);


	virtual void handleCollision(Static& staticObject) = 0;


	sf::Vector2f getMoveDirection() const;
	void setMoveDirection(const sf::Vector2f newDirection);


protected:
	sf::Vector2f m_moveDirection;


private:
//		true - faces right, false - faces left
	bool m_isFacedRight;



//		returns current direction the object is facing
	bool getDirection() const;

};