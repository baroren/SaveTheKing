#include "GameController.h"

#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()
	:m_window(sf::Vector2u(1400, 700), "Dungeon Edition")
{
	
}


void GameController::run()
{
	while (m_window.isOpen())
	{
		m_window.display();

		handleKey();
	}
}

void GameController::handleKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		cout << "wat" << endl;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		cout << "ey" << endl;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		m_window.close();
}