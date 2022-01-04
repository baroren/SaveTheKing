
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()
{
    m_movingObjects.push_back(make_unique<Mage> (450, 150, 2, 3, 0.17, 3, "Mage.png", false));

    
}


void GameController::run()
{

 
    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;
    float deltaTime;
    int key = 0;
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
     // m_gameObjects[1]->path();
        for (int i = 0; i < 1; i++)
        {
            m_movingObjects[i]->updateAndDraw(0, deltaTime, m_window.getWindow());

        }

        m_window.display();

		handleKey(deltaTime,key);
	}
}

void GameController::handleKey(float deltaTime,int &key)
{


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P ))
    {
       // cout <<"test";
       // if(key==0)
       // {
       //     key=1;
       //     cout << key<<"1\n";
       // }
       //else if(key ==1) {
       //     key = 0;
       //     cout << key << "0\n";
       // }
    }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
       // running = false;   //why tho?

        m_window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {


    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_movingObjects[key]->move(left,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_movingObjects[key]->move(right,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_movingObjects[key]->move(up,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_movingObjects[key]->move(down,deltaTime);
    }

}
bool GameController::isRunning()
{
    return running;
}