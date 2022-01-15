
#include "GameObject.h"

#include <iostream>


using std::cout;
using std::endl;

GameObject::GameObject(const  sf::Vector2f position,gameObjectId id,float scale)


{
  /*  if (!m_texture.loadFromFile(m_imagePath))
    {
        // error...
        std::cout<<"error loading font";

    }
   //m_texture=Resources::instance().getTexture(0);
    m_sprite.setTexture(m_texture);
    m_animation =new Animation(&m_texture,sf::Vector2u(numOfFrames,numOfAnim),animTime);

    m_sprite.setOrigin(m_sprite.getGlobalBounds().width/(numOfFrames) /2.f,m_sprite.getGlobalBounds().height / (numOfAnim) /2.f);

    m_sprite.setPosition(position);

    m_sprite.scale(scale, scale);// need to make func
    */

    m_texture=Resources::instance().getTexture(id);
    m_sprite=Resources::instance().getSprite(id);
    m_animation =new Animation(&m_texture,sf::Vector2u(Resources::instance().getNunOfFrames(id),1),0.17);
    m_sprite.setPosition(position);

    m_sprite.scale(scale, scale);// need to make func

    //cout << "scale x: " << m_sprite.getScale().x << " y: " << m_sprite.getScale().y << endl;

    //cout << "origin x: " << m_sprite.getOrigin().x << " y: " << m_sprite.getOrigin().y << endl;
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

void GameObject::setLocation(const sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

sf::Vector2<float> GameObject::getLocation( ) const
{
    return m_sprite.getPosition();
}