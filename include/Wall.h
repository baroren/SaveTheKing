#pragma once

#include "Static.h"
#include "Mage.h"

class Wall : public Static {

public:

	using Static::Static;

	virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) override;
	virtual void handleCollision(Wall& wall, const sf::Vector2f moveDirection) override;


private:



};