
#include "GameController.h"


#include <iostream>

using std::cout;
using std::endl;

GameController::GameController() {

	m_levelTime = 80;


	

	m_currPlayer.setSize(sf::Vector2f(30, 3));
	m_currPlayer.setOutlineColor(sf::Color::Transparent);
	m_currPlayer.setOutlineThickness(1);
	m_currPlayer.setOrigin(sf::Vector2f(m_currPlayer.getGlobalBounds().width - 30.f,
		m_currPlayer.getGlobalBounds().height - 40.f));

	//creatring the side menu
	m_menu.createButton("New Game", 100, 225);
	m_menu.createButton("help", 100, 300);
	m_menu.createButton("restart level", 100, 375);
	m_menu.createButton("music on", 100, 450);
	m_menu.createButton("Quit", 100, 525);

	if (!m_music.openFromFile("barGameBg.ogg")) {
		// error...
		std::cout << "error loading music";

	}
	m_font = Resources::instance().getFont();


	m_timer.setFont(m_font);
	m_timer.setOrigin(sf::Vector2f(m_timer.getGlobalBounds().width / 2.f,
		m_timer.getGlobalBounds().height / 2.f));
	m_timer.setPosition(sf::Vector2f(50, 75));
	m_level.setFont(m_font);
	m_level.setOrigin(sf::Vector2f(m_timer.getGlobalBounds().width / 2.f,
		m_timer.getGlobalBounds().height / 2.f));
	m_level.setPosition(sf::Vector2f(50, 30));

}




void GameController::run(int level)
{
	m_window.createBoard(level);
	storeObjects();
	storePlayers();
	storeSurroundWall();

	m_music.play();
	m_mainMenu.run(m_window.getWindow());

	sf::Clock clock;

	int key = 0;
	sf::Vector2f moveDirection;
	m_clock = new Clock(m_levelTime);
	m_clock->reset();

	while (m_window.isOpen())
	{


		m_window.getWindow().clear(sf::Color(34, 20, 26));


		m_deltaTime = clock.restart().asSeconds();
		m_timer.setString(m_clock->countDown());
		m_level.setString("Level" + std::to_string(level));



		handleCollision(key);

		if (m_players[thief]->getLevelPassed())
		{
			m_keyShow->setOpacity(255);
		}
		else
			m_keyShow->setOpacity(128);

		if (m_players[king]->getLevelPassed())
		{

			level++;
			resetLevel(level,"level"+std::to_string(level));


		}
		if (m_players[key]->getLevelFailed() || m_clock->isGameOver())
		{
			resetLevel(level, "try again");

		}

		destroyObjects(key);
		m_window.displayBoard();


		drawObjects(key);


		m_menu.updateBt(m_window.getWindow());
		sf::Event event;
		if (m_window.getWindow().pollEvent(event))
		{

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					handleMenuClick(level);

				}
			}
			switch (event.type) {
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
		//check if pressed outside of help box
		if (m_menu.helpPressed()) {
			std::cout << "help pressed" << endl;
			m_window.getWindow().draw(m_menu.getHelp());
		}
		m_window.display();

		handleKey(m_deltaTime, key, moveDirection);

	}
	
}
void GameController::handleMenuClick(int level)
{
	if (m_menu.handleClick(m_window.getWindow().
		mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())), m_window.getWindow()) == 0) {
		resetLevel(1, "continue");


	}
	if (m_menu.handleClick(m_window.getWindow().
		mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())), m_window.getWindow()) == 2)
	{

		resetLevel(level, "continue");
	}


	if (m_menu.handleClick(m_window.getWindow().
		mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())), m_window.getWindow()) == 4) {
		m_window.getWindow().close();
		m_isRuning = false;
	}
	if (m_menu.handleClick(m_window.getWindow().
		mapPixelToCoords(sf::Mouse::getPosition(m_window.getWindow())), m_window.getWindow()) == 3) {
		if (m_music.getVolume() > 0) {
			m_music.setVolume(0.f);
			m_menu.changeText("Music off");

		}
		else {
			m_music.setVolume(100.f);
			m_menu.changeText("Music on");
		}


	}
}
void GameController::resetLevel(int level,string text)
{
	clearVectors();
	m_window.deletBoard();
	m_mainMenu.changeText(text);
	m_mainMenu.run(m_window.getWindow());
	m_window.createBoard(level);

	storePlayers();
	storeSurroundWall();
	storeObjects();

	m_clock = new Clock(m_levelTime);
}
bool GameController::isRuning()
{
	return m_isRuning;
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

			m_teleporters.push_back(make_unique<Teleporter>(foundPos_1, teleport, 3));
			m_teleporters.push_back(make_unique<Teleporter>(foundPos_2, teleport, 3));

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

	for (int i = 0; i < rowColNum.y; i++)
	{
		m_blockObjects.push_back(make_unique<Wall>(sf::Vector2f(firstHorizontalX + i * SQUARE, upperLeftDot.y - 15), horiWall, 3));
		m_blockObjects.push_back(make_unique<Wall>(sf::Vector2f(firstHorizontalX + i * SQUARE, upperLeftDot.y + rowColNum.x * SQUARE + 15), horiWall, 3));
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

	m_window.drawText(m_timer);
	m_window.drawText(m_level);
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
	m_keyShow->updateAndDraw(0, m_deltaTime, m_window.getWindow());
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


void GameController::handleKey(float deltaTime, int& key, sf::Vector2f& moveDirection)
{
	//handle key press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{


		m_window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{


	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_players[key]->move(LEFT, deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_players[key]->move(RIGHT, deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_players[key]->move(UP, deltaTime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_players[key]->move(DOWN, deltaTime);
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
void GameController::resetPosition()
{
	for (int i = 0; i < m_players.size(); i++) {
		m_players[i]->setOriginalPosition();
	}
	if (m_dwarves.size() == 0)
	{
		m_dwarves.push_back(make_unique<Dwarf>(m_window.calculatePos('&'), dwarf, 3, true, sf::Vector2f(1, 0)));

	}

}
void GameController::storePlayers()
{
	//making player vetor


	m_players.push_back(make_unique<King>(m_window.calculatePos('K'), king, 3, true));
	m_players.push_back(make_unique<Mage>(m_window.calculatePos('M'), mage, 3, false));
	m_players.push_back(make_unique<Warrior>(m_window.calculatePos('W'), warrior, 3, false));
	m_players.push_back(make_unique<Thief>(m_window.calculatePos('T'), thief, 3, true));

	m_playerShow.push_back(make_unique<King>(sf::Vector2f(75, 150), king, 3, true));
	m_playerShow.push_back(make_unique<Mage>(sf::Vector2f(75, 150), mage, 3, false));
	m_playerShow.push_back(make_unique<Warrior>(sf::Vector2f(75, 150), warrior, 3, false));
	m_playerShow.push_back(make_unique<Thief>(sf::Vector2f(75, 150), thief, 3, true));
}



void GameController::storeObjects() {
	sf::Vector2f foundPos;
	foundPos = m_window.calculatePos(dwarfChar);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_dwarves.push_back(make_unique<Dwarf>(foundPos, dwarf, 3, false, sf::Vector2f(1, 0)));
		foundPos = m_window.calculatePos(dwarfChar);
		cout << "hi";
	}
	foundPos = m_window.calculatePos(timeGift);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_gifts_1.push_back(make_unique<Gift_1>(foundPos, gift1, 3));
		foundPos = m_window.calculatePos(timeGift);
	}
	foundPos = m_window.calculatePos(killDwarf);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_gifts_2.push_back(make_unique<Gift_2>(foundPos, gift2, 3));
		foundPos = m_window.calculatePos(killDwarf);
	}
	//only one throne dont need to check for more 
	foundPos = m_window.calculatePos(throneChar);
	m_specialStatic.push_back(make_unique<Throne>(foundPos, throne, 3));


	foundPos = m_window.calculatePos(fireChar);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_blockObjects.push_back(make_unique<Fire>(foundPos, fire, 3));
		foundPos = m_window.calculatePos(fireChar);
		cout << "hi";
	}
	foundPos = m_window.calculatePos(gateChar);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_blockObjects.push_back(make_unique<Gate>(foundPos, gate, 3));
		foundPos = m_window.calculatePos(gateChar);
		cout << "hi";
	}

	foundPos = m_window.calculatePos(keyChar);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_specialStatic.push_back(make_unique<Key>(foundPos, key, 3));
		foundPos = m_window.calculatePos(keyChar);
	}
	foundPos = m_window.calculatePos(wallChar);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_blockObjects.push_back(make_unique<Wall>(foundPos, boxWall, 3));
		foundPos = m_window.calculatePos(wallChar);
	}
	foundPos = m_window.calculatePos(trollChar);
	while (foundPos != sf::Vector2f(-1.f, -1.f)) {
		m_blockObjects.push_back(make_unique<Orc>(foundPos, orc, 3));
		foundPos = m_window.calculatePos(trollChar);
		cout << "hi";
	}
	m_keyShow = make_unique<Key>(sf::Vector2f(150, 150), key, 3);
	m_keyShow->setOpacity(128);
	storeTeleproters();
}



bool GameController::isRunning()
{
	return running;
}
void GameController::cangeMenu(string game) {
	m_mainMenu.changeText(game);
}
void GameController::clearVectors()
{
	m_players.clear();
	m_dwarves.clear();
	m_blockObjects.clear();
	m_specialStatic.clear();
	m_gifts_1.clear();
	m_gifts_2.clear();
	m_teleporters.clear();
}
