#pragma once
#include <vector>
#include "Window.h"
#include "GameObject.h"
#include "MainMenu.h"

using std::vector;

class GameController {

public:
	
	GameController();

	void run(sf::RenderWindow);

	void handleKey();


private:
    //MainMenu mainMenu;
    sf::RenderWindow m_window;
	vector <GameObject> m_gameObjects;

};