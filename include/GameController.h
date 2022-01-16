#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include "Menu.h"
#include "Window.h"
#include "GameObject.h"
#include "MainMenu.h"
#include "Board.h"
#include "Wall.h"
#include "Dwarf.h"
#include "Clock.h"
#include "Teleporter.h"
#include "Gate.h"
#include "King.h"
#include "Warrior.h"
#include "Thief.h"
#include "Fire.h"
#include "Gift_1.h"
#include "Gift_2.h"
#include "Throne.h"


using std::vector;
using std::unique_ptr;
using std::make_unique;

class GameController {

public:
	
	GameController();

	void run();
    bool isRunning();
	void handleKey(float deltaTime,int &key, sf::Vector2f& moveDirection);

	void storeTeleproters();


private:
    bool running = true;
	float m_deltaTime;
    MainMenu m_mainMenu;
	Window m_window;
    Clock *m_clock;

	void storePlayers();

//reset to original level position
    void  resetPosition();

//  handles collision that have a block affect on the moving object
	void handleCollision(Moving& movingObject);

//  handle collisions of current player with static objects special for the player (throne, teleporters, key)
	void handleCollision(const int key);

//		handle collisions of current player with teleporters
	void handleTeleporters(const int key);

	void storeSurroundWall();

	void replaceOrcWithKey();

	void drawObjects(const int key);

	void destroyObjects(const int key);

    sf:: Font m_font;
    Menu m_menu;
    sf::Text m_timer;
    sf::RectangleShape m_currPlayer;
    unique_ptr<Static> m_keyShow;
    sf::Music m_music;



//		vector of the player objects (mage, king etc)
	vector <unique_ptr<Player>> m_players;
	vector <unique_ptr<Dwarf>> m_dwarves;
    vector <unique_ptr<Player>> m_playerShow;
//	vector of static objects that block the moving objects (wall, fire, gate, orc)
	vector <unique_ptr<Static>> m_blockObjects;
//		vector of other static objects that affect only the player objects (throne, key)
	vector <unique_ptr<Static>> m_specialStatic;

	vector <unique_ptr<Gift_1>> m_gifts_1;
	vector <unique_ptr<Gift_2>> m_gifts_2;



//		vector of all teleports
	vector <unique_ptr<Teleporter>> m_teleporters;
    int m_levelTime;

    void storeObjects();
};