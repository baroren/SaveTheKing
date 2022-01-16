#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>
#include <string>
#include "Static.h"
#include "Wall.h"


using std::vector;
using std::unique_ptr;
using std::make_unique;

using std::string;

//	size of squares in the game board
#define SQUARE 100

class Board {

public:
//		where the actual game will take place
	Board(int level=1);

//		display the game board on window
	void display(sf::RenderWindow& window);

	sf::Vector2f convertIndexToPixel(const int rowIndex, const int colIndex);

//		using a tag name, the func searches for the tag on matrix and 
//		returns the appropriate position on window
	sf::Vector2f calculatePos(const char tag);

	sf::Vector2f getUpperLeftDot() const;

	sf::Vector2i getRowColNum() const;
    void createBoard(int level);
    void deletBoard();

private:
    sf::Texture m_boardTexture; //temp
    sf::RectangleShape m_sprite;//temp
//		default upper left dot, depends on SQUARE. currently is 400 200
	 sf::Vector2f m_upperLeftDot;
	int m_rowNum, m_colNum;
    //	vector of static objects that block the moving objects (wall, fire, gate, orc)
    vector <unique_ptr<Static>> m_wall;
	vector<string> m_btsBoard;


};