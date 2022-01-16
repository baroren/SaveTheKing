#include "Board.h"

#include <iostream>
#include <fstream>

using std::ifstream;
using std::getline;
using std::cout;
using std::endl;

Board::Board(int level)

{
    m_boardTexture=Resources::instance().getTexture(map);
      m_sprite.setTexture(&m_boardTexture);

  //  createBoard(level);


//    m_wall.push_back(make_unique<Wall>(sf::Vector2f(m_upperLeftDot.x + 50, m_upperLeftDot.y), vertWall,3));



}

void Board::createBoard(int level) {
    ifstream inputFile;

    inputFile.open("Level_"+std::to_string(level)+".txt");

    if (!inputFile.is_open())
    {
        cout << "file failed to open" << endl;
        exit(EXIT_FAILURE);
    }

    inputFile >> m_rowNum >> m_colNum;       //stores board size from file input
    m_upperLeftDot =sf::Vector2f(((14 - m_colNum + 1) / 2) * SQUARE, SQUARE);

    inputFile.ignore();

    string line;
    while (getline(inputFile, line))
    {
        m_btsBoard.push_back(line);
    }

    inputFile.close();
}

sf::Vector2f Board::calculatePos(const char tag)
{
	const int colNum = m_btsBoard[0].size(),
		rowNum = m_btsBoard.size();

	for (int currRow = 1; currRow < rowNum - 1; currRow++)
	{
		for (int currCol = 1, correctCol = 1; currCol < colNum; currCol += 2, correctCol++)
		{
//				when found store coordinates and delete it from the board
			if (m_btsBoard[currRow][currCol] == tag)
			{
				m_btsBoard[currRow][currCol] = ' ';
				return convertIndexToPixel(currRow, correctCol);
			}
		}
	}

//		return it if no tag name was found
	return sf::Vector2f(-1, -1);
}


void Board::display(sf::RenderWindow& window)
{


    sf::Vector2f upperRightDot = sf::Vector2f(m_upperLeftDot.x + m_colNum * SQUARE, m_upperLeftDot.y),
				lowerLeftDot = sf::Vector2f(m_upperLeftDot.x, m_upperLeftDot.y + m_rowNum * SQUARE),
				lowerRightDot = sf::Vector2f(upperRightDot.x, lowerLeftDot.y);

	sf::VertexArray quad(sf::Quads,4);
    quad[0].position =sf::Vector2f(m_upperLeftDot.x-SQUARE, m_upperLeftDot.y-SQUARE);
    quad[1].position =sf::Vector2f(upperRightDot.x+SQUARE, upperRightDot.y-SQUARE);
    quad[2].position = sf::Vector2f(lowerRightDot.x+SQUARE, lowerRightDot.y+SQUARE);
    quad[3].position =sf::Vector2f(lowerLeftDot.x-SQUARE, lowerLeftDot.y+SQUARE);
    quad[0].texCoords=sf::Vector2f(0,0);
    quad[1].texCoords=sf::Vector2f(80,0);
    quad[2].texCoords=sf::Vector2f(80,80);
    quad[3].texCoords=sf::Vector2f(0,80);



    sf::Vertex topLine[] = { m_upperLeftDot, upperRightDot };
    sf::Vertex bottomLine[] = { lowerLeftDot, lowerRightDot };
    sf::Vertex leftLine[] = { m_upperLeftDot, lowerLeftDot };
    sf::Vertex rightLine[] = { upperRightDot, lowerRightDot };
    window.draw(quad,&m_boardTexture);


}

sf::Vector2f Board:: getUpperLeftDot() const
{
	return m_upperLeftDot;
}

sf::Vector2i Board::getRowColNum() const
{
	return sf::Vector2i(m_rowNum, m_colNum);
}

void Board ::deletBoard()
{
    m_btsBoard.clear();
}
sf::Vector2f Board::convertIndexToPixel(const int rowIndex, const int colIndex)
{
	int x = m_upperLeftDot.x + SQUARE / 2,
		y = m_upperLeftDot.y + SQUARE / 2;

	x += (colIndex - 1) * SQUARE;
	y += (rowIndex - 1) * SQUARE;

	

	cout << "position: " << "x: " << x << " y: " << y << endl;


	return sf::Vector2f(x, y);
}