#include "SFML/Graphics.hpp"
#include <string>

using std::string;

class GameObject {
public:
	GameObject(const string imagePath, const int x, const int y);
	void draw();

private:

	sf::Vector2i m_location;

	sf::Vector2i indexToPixel(const int x, const int y);

	
};
 