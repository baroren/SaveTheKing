#pragma once

#include "Moving.h"

class Teleporter;

class Player : public Moving {
public:

    using Moving::Moving;
    void handleCollision(Teleporter& teleport);



private:


};