
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController() {
    m_players.push_back(make_unique<King>(m_window.calculatePos('K'), 2, 4, 0.17, 3, "King.png", true));
    m_players.push_back(make_unique<Mage>(m_window.calculatePos('M'), 1, 3, 0.17, 3, "Mage.png", false));
    m_players.push_back(make_unique<Warrior>(m_window.calculatePos('W'), 1, 3, 0.17, 3, "Warrior.png", false));
    m_players.push_back(make_unique<Thief>(m_window.calculatePos('T'), 1, 3, 0.17, 3, "Thief.png", true));



    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }
    m_timer.setFont(m_font);
    m_timer.setOrigin(sf::Vector2f(m_timer.getGlobalBounds().width / 2.f,
                                   m_timer.getGlobalBounds().height / 2.f));
    m_timer.setPosition(sf::Vector2f(150, 50));

}
void GameController::run()
{

    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;
    float deltaTime;
    int key = 0;
    sf::Vector2f moveDirection;
    m_clock =new Clock(234);
    m_clock->reset();
	while (m_window.isOpen())
	{

        m_window.getWindow().clear(sf::Color(34, 20, 26));


        sf::Event event;

        deltaTime = clock.restart().asSeconds();
        m_timer.setString(m_clock->countDown());
       cout <<m_clock->countDown()<<endl;
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

        m_window.displayBoard();

        for (int i = 0; i < m_players.size(); i++)
        {
            if (i != key)
                m_players[i]->updateAndDraw(0, deltaTime, m_window.getWindow());
        }
        m_players[key]->updateAndDraw(0, deltaTime, m_window.getWindow());

        for (int i = 0; i < m_static.size(); i++)
        {
            m_static[i]->updateAndDraw(0, deltaTime, m_window.getWindow());
        }
        m_window.drawText(m_timer);
        m_window.display();



	}
}

//void GameController::storeTeleproters()
//{
//    vector<unique_ptr<Teleporter>> currTeleporter_1, currTeleporter_2;
//    sf::Vector2f foundPos_1, foundPos_2;
//    while (true)
//    {
//        foundPos_1 = m_window.calculatePos('X');
//        foundPos_2 = m_window.calculatePos('X');
//
//        currTeleporter_1.push_back(make_unique<Teleporter>(m_window.calculatePos('X'), 1, 4, 0.17, 3, "Teleport.png"));
//        m_teleporters.push_back(currTeleporter_1);
//    }
//}

//  handles collision of the moving object with everybody
void GameController::handleCollision(Moving& movingObject, const sf::Vector2f moveDirection)
{
    for (auto& staticObject : m_static)
    {
        if (movingObject.checkCollision(*staticObject))
        {
            movingObject.handleCollision(*staticObject, moveDirection);
        }
    }
}


void GameController::handleKey(float deltaTime,int &key, sf::Vector2f& moveDirection)
{

    if(sf::Keyboard::isKeyPressed (sf::Keyboard::P))
    {
        (key == m_players.size() - 1) ? key = 0 : key++;
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