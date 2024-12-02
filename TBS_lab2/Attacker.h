#ifndef IATTACKER_H
#define IATTACKER_H

#include <string>
#include "Unit.h"

class IAttacker {
public:
    virtual void attack(Unit& unit) = 0; 
    virtual float getDamage() const = 0;
protected:
    virtual ~IAttacker() = default;
};

#endif // !IATTACKER_H
