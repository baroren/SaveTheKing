#pragma once

#include <vector>
#include "Window.h"
#include "GameObject.h"
#include "MainMenu.h"
#include "Board.h"

using std::vector;

class GameController {

public:
	
	GameController();

	void run();
    bool isRuning();
	void handleKey();


private:
    bool runing=true;
    MainMenu m_mainMenu;
	Window m_window;

	vector <GameObject> m_gameObjects;

};