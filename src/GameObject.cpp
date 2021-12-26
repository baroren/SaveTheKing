
#include "GameObject.h"

GameObject::GameObject(const string imagePath,const int x,const int y,
                       const int numOfAnim,const int numOfFrames,const float animTime, float scale,
                       const float posX,const float posY)
{
    if (!m_texture.loadFromFile(imagePath))
    {
        // error...
        std::cout<<"error loading font";

    }
    m_sprite.setTexture(m_texture);
    m_animation =new Animation(&m_texture,sf::Vector2u(numOfAnim,numOfFrames),animTime);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width/numOfFrames/2.f,m_sprite.getGlobalBounds().height/2.f);
    m_sprite.setPosition(sf::Vector2f(posX,posY));
    m_sprite.setScale(scale,scale);// need to make func
}