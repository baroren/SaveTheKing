#include "Teleporter.h"

#include "Player.h"

#include <iostream>

using std::cout;
using std::endl;

void Teleporter::setLinkedTeleporter(Teleporter& const otherTeleporter)
{
	m_linkedTeleporter = &otherTeleporter;
}

Teleporter* Teleporter::getLinkdedTeleporter() const
{
	return m_linkedTeleporter;
}

//void Teleporter::handleCollision(Player& player)
//{
//	cout << "TELEPORT" << endl;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
//	{
//		player.setLocation(this->getLinkdedTeleporter()->getLocation());
//	}
//}