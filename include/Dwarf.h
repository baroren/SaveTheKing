#pragma once

#include "Moving.h"

class Dwarf : public Moving {
public:
    Dwarf(const sf::Vector2f position, gameObjectId id, float scale, const bool isFacedRight, const sf::Vector2f moveDirection);

//    void handleCollision(Static& staticObject, const sf::Vector2f moveDirection) override {};
//    void handleCollision(Static& staticObject) override;
    virtual void handleCollision(Player& player)override {};
    virtual void handleCollision(Dwarf& dwarf) override {};

    virtual void handleCollision(Static& staticObject) override;
    

    void move(float deltaTime);

    void invertMove();




private:

};