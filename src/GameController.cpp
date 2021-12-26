
#include "GameController.h"

#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()

{

}


void GameController::run()
{

 
    m_mainMenu.run(m_window.getWindow());

    cout << "in game controller";

	while (m_window.isOpen())
	{
        sf::Event event;

        while (m_window.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

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
        runing=false;   //why tho?

        m_window.close();
    }

}
bool GameController:: isRuning()
{
    return runing;
}