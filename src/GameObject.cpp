
#include "GameObject.h"

GameObject::GameObject(const int x,const int y,
                       const int numOfAnim,const int numOfFrames,const float animTime, float scale,bool faceRight,string imagePath)
                       :m_imagePath(imagePath),m_isFacedRight(faceRight)

{
    if (!m_texture.loadFromFile(m_imagePath))
    {
        // error...
        std::cout<<"error loading font";

    }
    m_sprite.setTexture(m_texture);
    m_animation =new Animation(&m_texture,sf::Vector2u(numOfFrames,numOfAnim),animTime);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width/numOfFrames/2.f,m_sprite.getGlobalBounds().height/2.f);
    m_sprite.setPosition(sf::Vector2f(x,y));
    m_sprite.scale(scale,scale);// need to make func
}

void GameObject:: updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window)
{
    m_animation->update(row,deltaTime);
    m_sprite.setTextureRect(m_animation->getRect());
    window.draw(m_sprite);

}

void GameObject::setLocation(const float x, const float y )
{
    m_sprite.setPosition(sf::Vector2f(x,y));
}

sf::Vector2<float> GameObject::getLocation( ) const
{
    return m_sprite.getPosition();
}


void GameObject::move(const direction dir, float deltaTime)
{

    int x = 0, y = 0;
    const float speed = 100;

    switch (dir)                    //check what happens diagonally
    {
    case left:                  
        x = -1;
            if(m_isFacedRight) {

                m_sprite.scale(sf::Vector2f(-1, 1));
                m_isFacedRight = false;
            }

        break;

    case down:
        y = 1;
        break;

    case right:
        x = 1;
       // if (m_sprite.getScale().x > 0)
            if(!m_isFacedRight) {

                m_sprite.scale(sf::Vector2f(-1, 1));
                m_isFacedRight = true;
            }
            break;

    case up:
        y = -1;
        break;
    }

    sf::Vector2f direction(x, y);

    //sf::Vector2f updatedPos(m_sprite.getPosition().x + x, m_sprite.getPosition().y + y);

    //m_sprite.setPosition(updatedPos);

    m_sprite.move(direction * speed * deltaTime);
}

bool GameObject::getDirection()const
{
    return m_isFacedRight;
}