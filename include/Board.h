#pragma once

#include "SFML/Graphics.hpp"

//	size of squares in the game board
#define SQUARE 100

class Board {

public:
//		where the actual game will take place
	Board(const int rowNum = 5, const int colNum = 6);

//		display the game board on window
	void display(sf::RenderWindow& window);

	sf::Vector2f convertIndexToPixel(const int rowIndex, const int colIndex);

private:
//		default upper left dot, depends on SQUARE. currently is 400 100
	const sf::Vector2f m_upperLeftDot = sf::Vector2f(4 * SQUARE, SQUARE);
	int m_rowNUm, m_colNum;

};