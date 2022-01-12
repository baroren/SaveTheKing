#include "Board.h"

#include <iostream>

using std::cout;
using std::endl;

Board::Board(const int rowNum, const int colNum)
	:m_rowNUm(rowNum), m_colNum(colNum) {
    if (!m_boardTexture.loadFromFile("Map.png"))
    {
        cout<<"Eror";
    }
    m_sprite.setTexture(&m_boardTexture);
}


void Board::display(sf::RenderWindow& window)
{

	sf::Vector2f upperRightDot = sf::Vector2f(m_upperLeftDot.x + m_colNum * SQUARE, m_upperLeftDot.y),
				lowerLeftDot = sf::Vector2f(m_upperLeftDot.x, m_upperLeftDot.y + m_rowNUm * SQUARE),
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
/*	window.draw(topLine, 2, sf::Lines);
	window.draw(bottomLine, 2, sf::Lines);
	window.draw(leftLine, 2, sf::Lines);
	window.draw(rightLine, 2, sf::Lines);


    //m_sprite.setPosition(m_upperLeftDot.x -40.f, m_upperLeftDot.y-40.f);
    //m_sprite.setSize(sf::Vector2f(m_rowNUm * SQUARE, m_colNum * SQUARE));
   // window.draw(m_sprite);
	for (int i = 1; i < m_rowNUm; i++)
	{
		sf::Vertex horizontalLine[] = { sf::Vector2f(m_upperLeftDot.x, m_upperLeftDot.y + SQUARE * i),
										sf::Vector2f(upperRightDot.x, upperRightDot.y + SQUARE * i) };

		window.draw(horizontalLine, 2, sf::Lines);
	}

	for (int i = 1; i < m_colNum; i++)
	{
		sf::Vertex verticalLine[] = { sf::Vector2f(m_upperLeftDot.x + SQUARE * i, m_upperLeftDot.y),
										 sf::Vector2f(lowerLeftDot.x + SQUARE * i, lowerLeftDot.y) };

		window.draw(verticalLine, 2, sf::Lines);
	}*/

}


sf::Vector2f Board::convertIndexToPixel(const int rowIndex, const int colIndex)
{
	int x = m_upperLeftDot.x + SQUARE / 2,
		y = m_upperLeftDot.y + SQUARE / 2;

	x += (colIndex - 1) * SQUARE;
	y += (rowIndex - 1) * SQUARE;

	//x = m_upperLeftDot.x;
	//y = m_upperLeftDot.y;

	cout << "position: " << "x: " << x << " y: " << y << endl;


	return sf::Vector2f(x, y);
}