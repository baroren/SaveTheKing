
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;

GameController::GameController() {

    m_levelTime=80;



    storeObjects();

    m_specialStatic.push_back(make_unique<Throne>(m_window.calculatePos('@'), orc, 3));

    

    storePlayers();
    storeSurroundWall();




    m_currPlayer.setSize(sf::Vector2f(30, 3));
    m_currPlayer.setOutlineColor(sf::Color::Transparent);
    m_currPlayer.setOutlineThickness(1);
    m_currPlayer.setOrigin(sf::Vector2f(m_currPlayer.getGlobalBounds().width-30.f,
                                        m_currPlayer.getGlobalBounds().height-40.f));



//      store teleporters
    storeTeleproters();
    m_menu.createButton("New Game",100,150);
    m_menu.createButton("Help",100,225);
    m_menu.createButton("Main Menu",100,300);
    m_menu.createButton("music on",100,375);

    m_menu.createButton("Quit",100,450);

    if (!m_music.openFromFile("Shrek.ogg")) {
        // error...
        std::cout << "error loading music";

    }
     m_font=Resources::instance().getFont();


    m_timer.setFont(m_font);
    m_timer.setOrigin(sf::Vector2f(m_timer.getGlobalBounds().width / 2.f,
                                   m_timer.getGlobalBounds().height / 2.f));
    m_timer.setPosition(sf::Vector2f(50, 75));

}

void GameController::storeObjects() {
    m_blockObjects.push_back(make_unique<Wall>(m_window.calculatePos('='), boxWall, 3));
    m_blockObjects.push_back(make_unique<Fire>(m_window.calculatePos('*'), fire, 3));

    m_gifts_1.push_back(make_unique<Gift_1>(m_window.calculatePos('$'), gift1, 3));
    m_gifts_2.push_back(make_unique<Gift_2>(m_window.calculatePos('%'), gift2, 3));
    m_dwarves.push_back(make_unique<Dwarf>(m_window.calculatePos('&'), dwarf, 3, true, sf::Vector2f(1, 0)));
}

void GameController::run()
{

   // m_music.play();
    m_mainMenu.run(m_window.getWindow());

    sf::Clock clock;

    int key = 0;
    sf::Vector2f moveDirection;
    m_clock =new Clock(m_levelTime);
    m_clock->reset();

    while (m_window.isOpen())
    {


        m_window.getWindow().clear(sf::Color(34, 20, 26));


        m_deltaTime = clock.restart().asSeconds();
        m_timer.setString(m_clock->countDown());



        for (auto& currDwarf : m_dwarves)
        {
            currDwarf->move(m_deltaTime);
        }

//          check collisions of player and dwarf with any blocking object
        for (auto& currentPlayer : m_players)
        {
            handleCollision(*currentPlayer);
        }
        for (auto& currentDwarf : m_dwarves)
        {
            handleCollision(*currentDwarf);
        }
        handleCollision(key);




        destroyObjects(key);

        m_window.displayBoard();


        drawObjects(key);


        m_window.drawText(m_timer);
        m_menu.updateBt(m_window.getWindow());
       sf::Event event;
        if (m_window.getWindow().pollEvent(event))
        {

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(  m_menu.handleClick(m_window.getWindow().
                            mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),m_window.getWindow())==0) {
                       // std::erase_if(m_players, [](const auto& cuurPlayer) {return true; });
              //         m_players.clear();
                //      cout<<"deleted";
                     //   resetPosition();

                 //       m_clock =new Clock(m_levelTime);

                        //storePlayers();
                        //storeObjects();

                    }
                    if(  m_menu.handleClick(m_window.getWindow().
                      mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),m_window.getWindow())==2)
                        m_mainMenu.run(m_window.getWindow());

                    if(  m_menu.handleClick(m_window.getWindow().
                    mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),m_window.getWindow())==4)
                        m_window.getWindow().close();
                    if(  m_menu.handleClick(m_window.getWindow().
                            mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())),m_window.getWindow())==3) {
                        if(m_music.getVolume()>0) {
                            m_music.setVolume(0.f);
                            m_menu.changeText("Music off");

                        }
                        else {
                            m_music.setVolume(100.f);
                            m_menu.changeText("Music on");
                        }


                    }
                    std::cout<<"yeah";
                }
            }
            switch(event.type) {
                case sf::Event::KeyReleased: {

//          cycle on the player list
                    if (event.key.code == sf::Keyboard::P) {
                        (key == m_players.size() - 1) ? key = 0 : key++;
                    }
                    else if (event.key.code == sf::Keyboard::T) {
//          check collisions special for the player objects (throne, teleporters etc)
                        handleTeleporters(key);

                        cout << "test" << endl;
                    }

                    break;

                }

                case sf::Event::Closed: {
                    m_window.close();
                    break;
                }
            }
        }

        if(m_menu.helpPressed() ) {
            std::cout<<"help pressed"<<endl;
            m_window.getWindow().draw(m_menu.getHelp());
        }
        m_window.display();

        handleKey(m_deltaTime, key, moveDirection);
    }

}

void GameController::storeTeleproters()
{
    sf::Vector2f foundPos_1, foundPos_2;

    int teleIndex = 0, nextTeleIndex = 1;
    while (true)
    {
        foundPos_1 = m_window.calculatePos('X');
        foundPos_2 = m_window.calculatePos('X');

        if (foundPos_1.x != -1 && foundPos_2.x != -1)
        {

            m_teleporters.push_back(make_unique<Teleporter>(foundPos_1, teleport,3));
            m_teleporters.push_back(make_unique<Teleporter>(foundPos_2, teleport,3));

            m_teleporters[teleIndex]->setLinkedTeleporter(*m_teleporters[nextTeleIndex]);
            m_teleporters[nextTeleIndex]->setLinkedTeleporter(*m_teleporters[teleIndex]);

            teleIndex += 2;
            nextTeleIndex += 2;
        }

        else
            break;
    }
}



void GameController::storeSurroundWall()
{
    sf::Vector2f upperLeftDot = m_window.getUpperLeftDot();
    sf::Vector2i rowColNum = m_window.getRowColNum();

    float firstVerticalY = upperLeftDot.y + SQUARE / 2,
            firstHorizontalX = upperLeftDot.x + SQUARE / 2;

    for (int i = 0; i < rowColNum.x; i++)
    {
        m_blockObjects.push_back(make_unique<Wall>(sf::Vector2f(upperLeftDot.x - 15, firstVerticalY + i * SQUARE), vertWall, 3));
        m_blockObjects.push_back(make_unique<Wall>(sf::Vector2f(upperLeftDot.x + rowColNum.y * SQUARE + 15, firstVerticalY + i * SQUARE), vertWall, 3));
    }

    for (int i = 0; i < rowColNum.x; i++)
    {
        m_blockObjects.push_back(make_unique<Wall>(sf::Vector2f(firstHorizontalX + i * SQUARE, upperLeftDot.y - 15), horiWall, 3));
        m_blockObjects.push_back(make_unique<Wall>(sf::Vector2f( firstHorizontalX + i * SQUARE, upperLeftDot.y + rowColNum.x * SQUARE + 15), horiWall, 3));
    }
}


void GameController::handleCollision(Moving& movingObject)
{
//      check collisions with blocking objects
    for (auto& blockObject : m_blockObjects)
    {
        if (movingObject.checkCollision(*blockObject))
        {
            movingObject.handleCollision(*blockObject);
        }
    }
}

void GameController::handleCollision(const int key)
{
    for (auto& specialStatic : m_specialStatic)
    {
        if (m_players[key]->checkCollision(*specialStatic))
        {
            m_players[key]->handleCollision(*specialStatic);

            if (key == 0 && m_players[key]->getLevelPassed())
            {
                cout << "game is finised" << endl;
            }

            return;
        }
    }

    for (auto& currGift_1 : m_gifts_1)
    {
        if (m_players[key]->checkCollision(*currGift_1))
        {
            m_players[key]->handleCollision(*currGift_1, *m_clock);

            return;
        }
    }

    for (auto& currGift_2 : m_gifts_2)
    {
        if (m_players[key]->checkCollision(*currGift_2))
        {
            m_players[key]->handleCollision(*currGift_2, m_dwarves);

            return;
        }
    }

    for (auto& durrDwarf : m_dwarves)
    {
        if (m_players[key]->checkCollision(*durrDwarf))
        {
            m_players[key]->handleCollision(*durrDwarf);

            return;
        }
    }
}

void GameController::drawObjects(const int key)
{
    //          draw all teleporters
    for (int i = 0; i < m_teleporters.size(); i++)
    {
        m_teleporters[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    //          draw all blocking objects
    for (int i = 0; i < m_blockObjects.size(); i++)
    {
        m_blockObjects[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    //          draw all special static objects
    for (int i = 0; i < m_specialStatic.size(); i++)
    {
        m_specialStatic[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    for (int i = 0; i < m_gifts_1.size(); i++)
    {
        m_gifts_1[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    for (int i = 0; i < m_gifts_2.size(); i++)
    {
        m_gifts_2[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    //          draw all dwarves
    for (int i = 0; i < m_dwarves.size(); i++)
    {
        //  if(m_dwarves[i]->getDelete())
        m_dwarves[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    //          draw all players
    for (int i = 0; i < m_players.size(); i++)
    {

        if (i != key)
            m_players[i]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    }

    m_currPlayer.setPosition(m_players[key]->getLocation());
    m_players[key]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
    m_window.getWindow().draw(m_currPlayer);

    m_playerShow[key]->updateAndDraw(0, m_deltaTime, m_window.getWindow());
}

void GameController::handleTeleporters(const int key)
{
    for (auto& teleporter : m_teleporters)
    {
        if (m_players[key]->checkCollision(*teleporter))
        {
            m_players[key]->handleCollision(*teleporter);

            return;
        }
    }
}


void GameController::handleKey(float deltaTime,int &key, sf::Vector2f& moveDirection)
{

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
        m_players[key]->move(LEFT,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_players[key]->move(RIGHT,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_players[key]->move(UP,deltaTime);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_players[key]->move(DOWN,deltaTime);
    }

}

void GameController::destroyObjects(const int key)
{
//      if player controlls the warrior destroy the killed orc with key
    if (key == 2)
        replaceOrcWithKey();

//          destroy static objects
    std::erase_if(m_blockObjects, [](const auto& currBlockObject) {return currBlockObject->getDelete(); });
    std::erase_if(m_specialStatic, [](const auto& currSpecialObject) {return currSpecialObject->getDelete(); });
    std::erase_if(m_gifts_1, [](const auto& currGift_1) {return currGift_1->getDelete(); });
    std::erase_if(m_gifts_2, [](const auto& currGift_2) {return currGift_2->getDelete(); });
}

void GameController::replaceOrcWithKey()
{
    for (auto& currOrc : m_blockObjects)
    {
        if (currOrc->getDelete())
        {
            m_specialStatic.push_back(make_unique<Key>(currOrc->getLocation(), key, 3));
            break;
        }
    }
}
void GameController:: resetPosition()
{
    for (int i = 0; i < m_players.size(); i++) {
        m_players[i]->setOriginalPosition();
    }
    if(m_dwarves.size() ==0)
    {
        m_dwarves.push_back(make_unique<Dwarf>(m_window.calculatePos('&'), dwarf, 3, true, sf::Vector2f(1,0)));

    }

}
void GameController::storePlayers()
{
    m_players.push_back(make_unique<King>(m_window.calculatePos('K'), king, 3, true));
    m_players.push_back(make_unique<Mage>(m_window.calculatePos('M'), mage, 3, false));
    m_players.push_back(make_unique<Warrior>(m_window.calculatePos('W'), warrior, 3, false));
    m_players.push_back(make_unique<Thief>(m_window.calculatePos('T'), thief, 3, true));

    m_playerShow.push_back(make_unique<King>(sf::Vector2f(100, 800), king, 3, true));
    m_playerShow.push_back(make_unique<Mage>(sf::Vector2f(100, 800), mage, 3, false));
    m_playerShow.push_back(make_unique<Warrior>(sf::Vector2f(100, 800), warrior, 3, false));
    m_playerShow.push_back(make_unique<Thief>(sf::Vector2f(100, 800), thief, 3, true));
}

bool GameController::isRunning()
{
    return running;
}