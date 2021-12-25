#pragma once
#include <vector>
#include "Window.h"
#include "GameObject.h"


using std::vector;

class GameController {

public:
	
	GameController();

	void run(sf::RenderWindow);
    bool isRuning();
	void handleKey();


private:
    bool runing=true;
    //MainMenu mainMenu;
    sf::RenderWindow m_window;
	vector <GameObject> m_gameObjects;

};