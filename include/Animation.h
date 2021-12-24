#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public :
    Animation(sf::Texture* texture,sf::Vector2u imageCount,
              float switchTime);
    void update(int row,float deltaTime);
    sf::IntRect getRect();


private:
  //  sf::IntRect uvRect;
    sf::IntRect m_uvRect; // make a get and set

    sf::Vector2u m_imageCount;
    sf::Vector2u m_currentImage;
    float m_totalTime;
    float m_switchTime;
};
