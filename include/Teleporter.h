#pragma once

#include <Static.h>

class Player;

class Teleporter : public Static {

public:

	using Static::Static;


	virtual void handleCollision(Player& player)override {};
	virtual void handleCollision(Mage& mage) override {};
	virtual void handleCollision(Dwarf& dwarf) override {};



	void setLinkedTeleporter(Teleporter& const otherTeleporter);



	Teleporter* getLinkdedTeleporter() const;




private:

	Teleporter* m_linkedTeleporter = NULL;

};