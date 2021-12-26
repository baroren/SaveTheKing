#include "Window.h"

#include <iostream>

using std::cout;
using std::endl;

Window::Window(const sf::Vector2u windowSize, const string title)
	: m_window(sf::VideoMode(windowSize.x, windowSize.y), title) {}

void Window::display()
{

	m_window.clear(sf::Color(34, 20, 26));
	m_board.display(m_window);
	m_window.display();

	if (sf::Event event; m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
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