#include "Resources.h"
Resources::Resources() {
    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }
    buildTexture();
    buildSprite();
    //add sound
}
void Resources::buildTexture() {
    for(int i=0;i<m_imagePath.size();i++) {
        if (!m_temp.loadFromFile(m_imagePath[i])) {
            // error...
            std::cout << "error loading font";

        }
        m_texture.push_back(m_temp);
    }
}
sf::Font& Resources::getFont()
{
    return m_font;
}
sf::Texture& Resources::getTexture(int i)
{
    return m_texture[i];

}
sf::Sprite& Resources::getSprite(int i)
{
    return m_sprite[i];

}
void Resources::buildSprite()
{
    for(int i=0;i<m_imagePath.size();i++) {
        sf::Sprite temp;
        temp.setTexture(m_texture[i]);
        m_sprite.push_back(temp);
    }
}
Resources& Resources:: instance(){
    static auto resources=Resources();
    return resources;
}
Animation* Resources::getAnimation(int i)
{
    return m_animation[i];
}
void Resources :: buildAnimation()
{
    for(int i=0; i<m_texture.size();i++) {
        m_animation.push_back(new Animation((&m_texture[i]),sf::Vector2u(numOfFrames[i],numOfAnim[i]),0.17));
    }
}