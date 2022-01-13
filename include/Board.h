#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>


using std::vector;
using std::string;

//	size of squares in the game board
#define SQUARE 100

class Board {

public:
//		where the actual game will take place
	Board(int rowNum = 5, int colNum = 5);

//		display the game board on window
	void display(sf::RenderWindow& window);

	sf::Vector2f convertIndexToPixel(const int rowIndex, const int colIndex);

//		using a tag name, the func searches for the tag on matrix and 
//		returns the appropriate position on window
	sf::Vector2f calculatePos(const char tag);

private:
    sf::Texture m_boardTexture; //temp
    sf::RectangleShape m_sprite;//temp
//		default upper left dot, depends on SQUARE. currently is 400 200
	 sf::Vector2f m_upperLeftDot;
	int m_rowNum, m_colNum;

	vector<string> m_btsBoard;

};