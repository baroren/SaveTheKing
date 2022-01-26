

#include "Moving.h"

#include <iostream>

using std::endl;
using std::cout;

Moving::Moving(const sf::Vector2f position, gameObjectId id, float scale, const bool isFacedRight, const sf::Vector2f moveDirection)
    :GameObject(position, id, scale), m_isFacedRight(isFacedRight) {}


void Moving::move(const Direction dir, float deltaTime)
{

    int x = 0, y = 0;
    m_moveDirection = sf::Vector2f(x, y);
    const float speed = 100;

    switch (dir)
    {
    case LEFT:
        m_moveDirection.x = x = -1;
        if (m_isFacedRight)
        {
            m_sprite.scale(sf::Vector2f(-1, 1));
            m_isFacedRight = false;
        }

        break;

    case DOWN:
        m_moveDirection.y = y = 1;
        break;

    case RIGHT:
        m_moveDirection.x = x = 1;
        if (!m_isFacedRight)
        {
            m_sprite.scale(sf::Vector2f(-1, 1));
            m_isFacedRight = true;
        }
        break;

    case UP:
        m_moveDirection.y = y = -1;
        break;
    }

    sf::Vector2f direction(x, y);

    m_sprite.move(direction * speed * deltaTime);
}

void Moving::setMoveDirection(const sf::Vector2f newDirection)
{
    m_moveDirection = newDirection;
}

sf::Vector2f Moving::getMoveDirection() const
{
    return m_moveDirection;
}





//	collision with wall
//void Moving::handleCollision(Wall& wall, const sf::Vector2f moveDirection)
//{
//
//}



bool Moving::getDirection() const
{
    return m_isFacedRight;
}