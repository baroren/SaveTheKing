

#include "Moving.h"

#include <iostream>

using std::endl;
using std::cout;

Moving::Moving(const int x, const int y, const int numOfAnim, const int numOfFrames, const float animTime,
                const float scale, const string imagePath, const bool isFacedRight)
    :GameObject(x, y, numOfAnim, numOfFrames, animTime, scale, imagePath), m_isFacedRight(isFacedRight) {}

void Moving::move(const Direction dir, float deltaTime, sf::Vector2f& moveDirection)
{

    int x = 0, y = 0;
    moveDirection = sf::Vector2f(x, y);
    const float speed = 100;

    switch (dir)
    {
    case LEFT:
        moveDirection.x = x = -1;
        if (m_isFacedRight)
        {
            m_sprite.scale(sf::Vector2f(-1, 1));
            m_isFacedRight = false;
        }

        break;

    case DOWN:
        moveDirection.y = y = 1;
        break;

    case RIGHT:
        moveDirection.x = x = 1;
        if (!m_isFacedRight)
        {
            m_sprite.scale(sf::Vector2f(-1, 1));
            m_isFacedRight = true;
        }
        break;

    case UP:
        moveDirection.y = y = -1;
        break;
    }

    sf::Vector2f direction(x, y);

    m_sprite.move(direction * speed * deltaTime);
}

//	collision with wall
void Moving::handleCollision(Wall& wall, const sf::Vector2f moveDirection)
{
    cout << "i am a mage, i collided with wall" << endl;
    this->m_sprite.move(sf::Vector2f(moveDirection.x * -1, moveDirection.y * -1));

}

bool Moving::getDirection() const
{
    return m_isFacedRight;
}