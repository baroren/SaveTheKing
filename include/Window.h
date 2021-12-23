#pragma once

#include "SFML/Graphics.hpp"

#include <string>

using std::string;

class Window {
public:
//		create window using size and title, default size is 50 50 and title ""
	Window(const sf::Vector2u windowSize = sf::Vector2u(50,50), const string title = "");

//		displays window, returns 1 if key pressed
	void display();
//		close window
	void close();
//		check if window is open
	bool isOpen() const;

private:
//		the window
	sf::RenderWindow m_window;
};