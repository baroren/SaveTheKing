
#include "GameObject.h"

#include <iostream>


using std::cout;
using std::endl;

GameObject::GameObject(const  sf::Vector2f position,gameObjectId id,float scale)


{
    m_originalPosition=position;


    m_texture=Resources::instance().getTexture(id);
    m_sprite=Resources::instance().getSprite(id);
    m_animation =new Animation(&m_texture,sf::Vector2u(Resources::instance().getNunOfFrames(id),1),0.17);
    m_sprite.setPosition(position);

    m_sprite.scale(scale, scale);// need to make func

}

void GameObject::setOriginalPosition()
{
   m_sprite.setPosition(m_originalPosition);
}

bool GameObject::checkCollision(const GameObject& gameObject)
{
    if (&gameObject == this)
        return false;

    return this->getSprite().getGlobalBounds().intersects(gameObject.getSprite().getGlobalBounds());
}

sf::Sprite GameObject::getSprite() const
{
    return m_sprite;
}

void GameObject:: updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window)
{
    m_animation->update(row,deltaTime);
    m_sprite.setTextureRect(m_animation->getRect());
    window.draw(m_sprite);
    
}

//  set location of the object
void GameObject::setLocation(const sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

sf::Vector2<float> GameObject::getLocation( ) const
{
    return m_sprite.getPosition();
}