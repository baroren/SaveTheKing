#include "Moving.h"

class Dwarf : public Moving {
public:
using Moving::Moving;

    Dwarf() : Moving(sf::Vector2f(), 0, 0, 0, 0, std::string(),  false) {}

    void path();


private:



};