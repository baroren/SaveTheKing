#include "Teleporter.h"

#include "Player.h"

#include <iostream>

using std::cout;
using std::endl;

void Teleporter::setLinkedTeleporter(Teleporter&  otherTeleporter)
{
	m_linkedTeleporter = &otherTeleporter;
}

sf::Vector2f Teleporter::getLinkdedTeleporterLocation() const
{
	return m_linkedTeleporter->getLocation();
}

//void Teleporter::handleCollision(Player& player)
//{
//	cout << "TELEPORT" << endl;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
//	{
//		player.setLocation(this->getLinkdedTeleporter()->getLocation());
//	}
//}