#include <vector>
#include "Window.h"
#include "GameObject.h"

using std::vector;

class GameController {

public:
	
	GameController();

	void run(sf::RenderWindow window);

	void handleKey();


private:

	Window m_window;
	vector <GameObject> m_gameObjects;

};