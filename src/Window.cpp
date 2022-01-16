#include "Window.h"

#include <iostream>

using std::cout;
using std::endl;

Window::Window(const sf::Vector2u windowSize, const string title)
	: m_window(sf::VideoMode(windowSize.x, windowSize.y), title) {}

void Window::display()
{


	m_window.display();

/*	if (sf::Event event; m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
*/
	m_window.clear(sf::Color(34, 20, 26));
}

sf::Vector2i Window::getRowColNum() const
{
	return m_board.getRowColNum();
}

sf::Vector2f Window::getUpperLeftDot() const
{
	return m_board.getUpperLeftDot();
}

sf::Vector2f Window::calculatePos(const char tag)
{
	return m_board.calculatePos(tag);
}
void Window::createBoard(int level)
{
    m_board.createBoard(level);
}

void Window::displayBoard()
{
    m_board.display(m_window);
}
sf::Vector2f Window::convertIndexToPixel(const int rowIndex, const int colIndex)
{
	return m_board.convertIndexToPixel(rowIndex, colIndex);
}
void Window:: drawText(sf::Text text)
{
    m_window.draw(text);
}

void Window::close()
{
	m_window.close();
}

bool Window::isOpen() const
{
	return m_window.isOpen();
}

sf::RenderWindow& Window::getWindow()
{
	return m_window;
}