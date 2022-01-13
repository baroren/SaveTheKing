
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;


GameController::GameController() {
    m_players.push_back(make_unique<Mage>(m_window.convertIndexToPixel(1, 1), 1, 3, 0.17, 3, "Dwarf.png", true));
    m_players.push_back(make_unique<Mage>(m_window.convertIndexToPixel(1, 4), 2, 4, 0.17, 3, "King.png", true));

    m_staticObjects.push_back(make_unique<Wall>(m_window.convertIndexToPixel(1, 2), 1, 1, 0.17, 3, "Gate.png"));
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
            m_players[i]->updateAndDraw(0, deltaTime, m_window.getWindow());

        }

        for (int i = 0; i < m_staticObjects.size(); i++)
        {
            m_staticObjects[i]->updateAndDraw(0, deltaTime, m_window.getWindow());
        }
        m_window.drawText(m_timer);
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        m_clock->addTime();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        m_clock->subTime();

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