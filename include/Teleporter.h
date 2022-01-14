#pragma once

#include <Static.h>

class Player;

class Teleporter : public Static {

public:

	using Static::Static;

	virtual void handleCollision(Moving& moving, const sf::Vector2f moveDirection)override {};
	virtual void handleCollision(GameObject& gameobject) override {};
//	virtual void handleCollision(Player& player, const sf::Vector2f moveDirection) {};
	virtual void handleCollision(Mage& mage, const sf::Vector2f moveDirection) override {};

	void setLinkedTeleporter(Teleporter&  otherTeleporter);

	Teleporter* getLinkdedTeleporter() const;




private:

	Teleporter* m_linkedTeleporter = NULL;

};