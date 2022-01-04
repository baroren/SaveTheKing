

#include "Moving.h"

Moving::Moving(const int x, const int y, const int numOfAnim, const int numOfFrames, const float animTime,
                const float scale, const string imagePath, const bool isFacedRight)
    :GameObject(x, y, numOfAnim, numOfFrames, animTime, scale, imagePath), m_isFacedRight(isFacedRight) {}

void Moving::move(const direction dir, float deltaTime)
{

    int x = 0, y = 0;
    const float speed = 100;

    switch (dir)
    {
    case left:
        x = -1;
        if (m_isFacedRight)
        {
            m_sprite.scale(sf::Vector2f(-1, 1));
            m_isFacedRight = false;
        }

        break;

    case down:
        y = 1;
        break;

    case right:
        x = 1;
        if (!m_isFacedRight)
        {
            m_sprite.scale(sf::Vector2f(-1, 1));
            m_isFacedRight = true;
        }
        break;

    case up:
        y = -1;
        break;
    }

    sf::Vector2f direction(x, y);

    m_sprite.move(direction * speed * deltaTime);
}

bool Moving::getDirection() const
{
    return m_isFacedRight;
}