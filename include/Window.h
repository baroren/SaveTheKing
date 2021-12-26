#pragma once

#include "SFML/Graphics.hpp"
#include "Board.h"
#include <string>

using std::string;

class Window {
public:

//		create window using size and title, default size is 50 50 and title ""
	Window(const sf::Vector2u windowSize = sf::Vector2u(1400,700), const string title = "Save The King: Dungeon Edition");

//		displays window
	void display();
//		close window
	void close();
//		check if window is open
	bool isOpen() const;

	sf::RenderWindow& getWindow();

private:
//		the window
	sf::RenderWindow m_window;
	Board m_board;
};