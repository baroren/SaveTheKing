
#include "GameController.h"

#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()

{
	
}


void GameController::run(sf::RenderWindow)
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
    {
        runing=false;
    }

}
bool GameController:: isRuning()
{
    return runing;
}