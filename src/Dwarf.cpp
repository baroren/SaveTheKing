
#include "Dwarf.h"

Dwarf::Dwarf(const sf::Vector2f position, gameObjectId id, float scale, const bool isFacedRight, 
                 const sf::Vector2f moveDirection)
    : Moving (position, id, scale, isFacedRight, moveDirection)
{
    m_moveDirection = moveDirection;

}

void Dwarf::handleCollision(Static& staticObject)
{
    staticObject.handleCollision(*this);
}


void Dwarf::move(float deltaTime)
{

    Direction direction;

//      moving on y axis
    if (getMoveDirection().x == 0)
    {
        if (m_moveDirection.y == 1)
            direction = DOWN;
        else
            direction = UP;
    }
//      moving on x axis
    else
    {
        if (m_moveDirection.x == 1)
            direction = RIGHT;
        else
            direction = LEFT;
    }

    Moving::move(direction, deltaTime);
}

void Dwarf::invertMove()
{
    m_moveDirection.x *= -1;
    m_moveDirection.y *= -1;
}