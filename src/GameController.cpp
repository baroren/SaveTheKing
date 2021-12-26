
#include "GameController.h"

#include <iostream>

using std::cout;
using std::endl;


GameController::GameController()

{

}


void GameController::run()
{
    sf::RenderWindow window(sf::VideoMode(1400, 700), "Save The king Dungen edition");
    mainMenu.run(window);
    std::cout << "in game controller";
	while (window.isOpen())
	{

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(34,20,26));



        window.display();

		handleKey();
	}
}

void GameController::handleKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		cout << "wat" << endl;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		cout << "ey" << endl;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        runing=false;
    }

}
bool GameController:: isRuning()
{
    return runing;
}