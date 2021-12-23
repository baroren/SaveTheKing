#include "SFML/Graphics.hpp"
#include "SFML/Graphics.hpp"


class Window {
public:
//		create window using size and title, default is 50 50 and title ""
	Window(const sf::Vector2u windowSize = sf::Vector2u(50,50), const string title = "");

private:
	sf::RenderWindow m_window;
};