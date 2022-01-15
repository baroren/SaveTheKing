#pragma once

#include "Static.h"
#include "Mage.h"
#include "Resources.h"

class Wall : public Static {

public:

	using Static::Static;


	virtual void handleCollision(Moving& moving, const sf::Vector2f moveDirection)override;
	virtual void handleCollision(GameObject& gameobject) override {};

	virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) override {};


private:



};