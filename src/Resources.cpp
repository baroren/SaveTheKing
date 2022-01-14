#include "Resources.h"
Resources::Resources() {
    if (!m_font.loadFromFile("arcadeClassic.ttf")) {
        // error...
        std::cout << "error loading font";

    }
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
sf::Font&Resources::getFont()
{
    return m_font;
}
sf::Texture Resources::getTexture(int i)
{
    return m_texture[i];
}