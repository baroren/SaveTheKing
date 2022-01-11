
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()
{
    m_players.push_back(make_unique<Mage> (m_window.convertIndexToPixel(1, 1), 2, 3, 0.17, 3, "Mage.png", false));

    m_staticObjects.push_back(make_unique<Wall>(m_window.convertIndexToPixel(1, 2), 1, 2, 0.17, 3, "skeleton2_v2.png"));
}


void GameController::run()
{

    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;
    float deltaTime;
    int key = 0;
    sf::Vector2f moveDirection;

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

        handleKey(deltaTime, key, moveDirection);

        for (auto& currentPlayer : m_players)
        {
            handleCollision(*currentPlayer, moveDirection);
        }

     
        for (int i = 0; i < m_players.size(); i++)
        {
            m_players[i]->updateAndDraw(0, deltaTime, m_window.getWindow());

        }

        for (int i = 0; i < m_staticObjects.size(); i++)
        {
            m_staticObjects[i]->updateAndDraw(0, deltaTime, m_window.getWindow());
        }

        m_window.display();



	}
}

//  handles collision of the moving object with everybody
void GameController::handleCollision(Moving& movingObject, const sf::Vector2f moveDirection)
{
    for (auto& staticObject : m_staticObjects)
    {
        if (movingObject.checkCollision(*staticObject))
        {
            movingObject.handleCollision(*staticObject, moveDirection);
        }
    }
}


void GameController::handleKey(float deltaTime,int &key, sf::Vector2f& moveDirection)
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
        m_players[key]->move(LEFT,deltaTime, moveDirection);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_players[key]->move(RIGHT,deltaTime, moveDirection);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_players[key]->move(UP,deltaTime, moveDirection);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_players[key]->move(DOWN,deltaTime, moveDirection);
    }

}
bool GameController::isRunning()
{
    return running;
}