#include "Board.h"

Board::Board(const int rowNum, const int colNum)
	:m_rowNUm(rowNum), m_colNum(colNum) {}


void Board::display(sf::RenderWindow& window)
{
	sf::Vector2f upperRightDot = sf::Vector2f(m_upperLeftDot.x + m_colNum * SQUARE, m_upperLeftDot.y),
				lowerLeftDot = sf::Vector2f(m_upperLeftDot.x, m_upperLeftDot.y + m_rowNUm * SQUARE),
				lowerRightDot = sf::Vector2f(upperRightDot.x, lowerLeftDot.y);

	sf::Vertex topLine[] = { m_upperLeftDot, upperRightDot };
	sf::Vertex bottomLine[] = { lowerLeftDot, lowerRightDot };
	sf::Vertex leftLine[] = { m_upperLeftDot, lowerLeftDot };
	sf::Vertex rightLine[] = { upperRightDot, lowerRightDot };

	window.draw(topLine, 2, sf::Lines);
	window.draw(bottomLine, 2, sf::Lines);
	window.draw(leftLine, 2, sf::Lines);
	window.draw(rightLine, 2, sf::Lines);
}