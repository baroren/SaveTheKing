#pragma once

#include "Moving.h"

class Dwarf : public Moving {
public:
    Dwarf(const sf::Vector2f position, const int numOfAnim, const int numOfFrames, const float animTime,
        const float scale, const string imagePath, const bool isFacedRight, const sf::Vector2f moveDirection);

//    void handleCollision(Static& staticObject, const sf::Vector2f moveDirection) override {};
//    void handleCollision(Static& staticObject) override;
    virtual void handleCollision(Player& player)override {};
    virtual void handleCollision(Dwarf& dwarf) override {};

    virtual void handleCollision(Static& staticObject) override;
    

    void move(float deltaTime);

    void invertMove();




private:

};