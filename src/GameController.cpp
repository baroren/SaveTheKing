
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController() {
    m_players.push_back(make_unique<King>(m_window.calculatePos('K'), 2, 4, 0.17, 3, "King.png", true));
    m_players.push_back(make_unique<Mage>(m_window.calculatePos('M'), 1, 3, 0.17, 3, "Mage.png", false));
    m_players.push_back(make_unique<Warrior>(m_window.calculatePos('W'), 1, 3, 0.17, 3, "Warrior.png", false));
    m_players.push_back(make_unique<Thief>(m_window.calculatePos('T'), 1, 3, 0.17, 3, "Thief.png", true));


    m_players_show.push_back(make_unique<King>(sf::Vector2f(100 ,800), 2, 4, 0.17, 5, "King.png", true));
    m_players_show.push_back(make_unique<Mage>(sf::Vector2f(100 ,800), 1, 3, 0.17, 5, "Mage.png", false));
    m_players_show.push_back(make_unique<Warrior>(sf::Vector2f(100 ,800), 1, 3, 0.17, 5, "Warrior.png", false));
    m_players_show.push_back(make_unique<Thief>(sf::Vector2f(100 ,800), 1, 3, 0.17, 5, "Thief.png", true));

    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }
    m_buttons.push_back(new Button(100, 150, 150, 50, &this->m_font, "New Game",
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));
    m_buttons.push_back(new Button(100, 225, 150, 50, &this->m_font, "Help",
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));
    m_buttons.push_back(new Button(100, 300, 150, 50, &this->m_font, "quit",
                                   sf::Color(70, 70, 70, 200), sf::Color(70, 3, 150, 200),
                                   sf::Color(70, 20, 20, 200)));

    m_timer.setFont(m_font);
    m_timer.setOrigin(sf::Vector2f(m_timer.getGlobalBounds().width / 2.f,
                                   m_timer.getGlobalBounds().height / 2.f));
    m_timer.setPosition(sf::Vector2f(50, 75));

}
void GameController::run()
{

    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;
    float deltaTime;
    int key = 0;
    sf::Vector2f moveDirection;
    m_clock =new Clock(80);
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

        for (int i = 0; i < 3; i++) {
            m_window.getWindow().draw(m_buttons[i]->render());
            m_window.getWindow().draw(m_buttons[i]->drawText());

            m_buttons[i]->update(m_window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())));
        }



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
        m_players_show[key]->updateAndDraw(0, deltaTime, m_window.getWindow());

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