#pragma once

#include "Moving.h"

class Player : public Moving {
public:

    using Moving::Moving;
private:


    Player() : Moving(sf::Vector2f(), 0, 0, 0, 0, std::string(), false) {}
};