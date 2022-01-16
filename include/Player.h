#pragma once

#include "Moving.h"
#include "Static.h"
#include "Gift_1.h"
#include "Gift_2.h"

#include <memory>

using std::unique_ptr;

class Teleporter;
class Fire;
class Key;
class Orc;
class Gate;
class Dwarf;
class Clock;
class Throne;


class Player : public Moving {
public:

    using Moving::Moving;
    virtual void handleCollision(Static& staticObject) override;
    void handleCollision(Teleporter& teleport);
    virtual void handleCollision(Player& player)override {};
    virtual void handleCollision(Dwarf& Dwarf)override;
    virtual void handleCollision(Mage& mage) override {};
    virtual void handleCollision(Fire& fire) = 0;
    virtual void handleCollision(Key& key) = 0;
    virtual void handleCollision(Orc& orc) = 0;
    virtual void handleCollision(Gate& gate) = 0;
    virtual void handleCollision(Throne& throne) = 0;
    void handleCollision(Gift_1& gift_1, Clock& clock);
    void handleCollision(Gift_2& gift_2, vector<unique_ptr<Dwarf>>&);

    virtual bool getLevelPassed() const = 0;
  //  virtual bool hasKey()const = 0;
    bool getLevelFailed() const;
    

    void stayInPlace();

private:


    bool m_levelFailed = false;


};