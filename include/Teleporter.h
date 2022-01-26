#pragma once

#include <Static.h>

class Player;

class Teleporter : public Static {

public:

	using Static::Static;


	virtual void handleCollision(Player& player)override {};
	virtual void handleCollision(Dwarf& dwarf) override {};



	void setLinkedTeleporter(Teleporter&  otherTeleporter);



	sf::Vector2f getLinkdedTeleporterLocation() const;




private:

	Teleporter* m_linkedTeleporter = NULL;

};