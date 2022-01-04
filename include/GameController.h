#pragma once

#include <vector>
#include <memory>
#include "Window.h"
#include "GameObject.h"
#include "MainMenu.h"
#include "Board.h"
#include "Dwarf.h"

using std::vector;
using std::unique_ptr;
using std::make_unique;

class GameController {

public:
	
	GameController();

	void run();
    bool isRunning();
	void handleKey(float deltaTime,int &key);

private:
    bool running = true;
    MainMenu m_mainMenu;
	Window m_window;

//		vector of all the objects in the game

	vector <unique_ptr<Moving>> m_movingObjects;
};