
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()
{
    m_gameObjects.push_back(new Mage(450, 150, 2, 3, 0.17, 3,false, "Mage.png"));

    m_gameObjects.push_back(new Orc(550, 150, 1, 4, 0.17, 3,true, "skeleton2_v2.png"));


}


void GameController::run()
{

 
    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;
    float deltaTime;
int key=1;
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
        for (int i = 0; i < 2; i++)
        {
            m_gameObjects[i]->updateAndDraw(0, deltaTime, m_window.getWindow());

        }

        m_window.display();

		handleKey(deltaTime,key);
	}
}

void GameController::handleKey(float deltaTime,int &key)
{


if(sf::Keyboard::isKeyPressed(sf::Keyboard::P ))
{
    cout <<"test";
    if(key==0)
    {
        key=1;
        cout << key<<"1\n";
    }
   else if(key ==1) {
        key = 0;
        cout << key << "0\n";
    }
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
        m_gameObjects[key]->move(left,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_gameObjects[key]->move(right,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_gameObjects[key]->move(up,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_gameObjects[key]->move(down,deltaTime);
    }

}
bool GameController::isRunning()
{
    return running;
}