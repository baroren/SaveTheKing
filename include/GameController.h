#pragma once
#include <vector>
#include "Window.h"
#include "GameObject.h"
#include "MainMenu.h"

using std::vector;

class GameController {

public:
	
	GameController();

	void run();
    bool isRuning();
	void handleKey();


private:
    bool runing=true;
    MainMenu mainMenu;
    sf::RenderWindow m_window;
	vector <GameObject> m_gameObjects;

};