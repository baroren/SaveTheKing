#include "Static.h"
#include "Player.h"

class Key : public Static {

public:

	using Static::Static;


	virtual void handleCollision(Player& player)override;
	virtual void handleCollision(Dwarf& dwarf)override {};

private:


};