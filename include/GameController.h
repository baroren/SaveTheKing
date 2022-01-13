#pragma once

#include <vector>
#include <memory>

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
    MainMenu m_mainMenu;
	Window m_window;
    Clock *m_clock;
	void handleCollision(Moving& movingObject, const sf::Vector2f moveDirection);
    sf:: Font m_font;

   sf::Text m_timer;
//		vector of the player objects (mage, king etc)
	vector <unique_ptr<Player>> m_players;
//		vector of all dwarves in the game
	vector <unique_ptr<Dwarf>> m_dwarves;	
//		vector of walls, gates, orc, keys, fire, gifts and throne
	vector <unique_ptr<Static>> m_static;
//		vector of all teleports
//		lists of size 2 vectors, each pair of teleports link together
	vector <vector<unique_ptr<Teleporter>>> m_teleporters;
};