#include "SFML/Graphics.hpp"
#include <string>
#include "Animation.h"
using std::string;

class GameObject {
public:
	GameObject(const string imagePath,const int x,const int y,
               const int numOfAnim,const int numOfFrames,const float animTime=0.17,const float scale,
               const float posX,const float posY);
	virtual void draw() =0;


private:
    Animation* m_animation;
	sf::Vector2i m_location;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
	//sf::Vector2i indexToPixel(const int x, const int y);

	
};
