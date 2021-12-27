
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()
{
    m_gameObjects.push_back(new Mage(450, 150, 1, 3, 0.17, 3, "W_Red_Idle_SPR.png"));
}


void GameController::run()
{

 
    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;
    float deltaTime;

	while (m_window.isOpen())
	{

        m_window.getWindow().clear(sf::Color(34, 20, 26));


        sf::Event event;

        deltaTime = clock.restart().asSeconds();

        while (m_window.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        for (int i = 0; i < 1; i++)
        {
            m_gameObjects[0]->updateAndDraw(0, deltaTime, m_window.getWindow());
        }

        m_window.display();

		handleKey();
	}
}

void GameController::handleKey()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        running = false;   //why tho?

        m_window.close();
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_gameObjects[0]->move(left);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_gameObjects[0]->move(right);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_gameObjects[0]->move(up);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_gameObjects[0]->move(down);
    }

}
bool GameController::isRunning()
{
    return running;
}