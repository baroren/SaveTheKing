#include "Moving.h"

class Dwarf : public Moving {
public:
using Moving::Moving;

    Dwarf() : Moving(sf::Vector2f(),dwarf ,3,false) {}

    void path();


private:



};