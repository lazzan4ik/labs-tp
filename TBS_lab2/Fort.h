#ifndef FORT_H
#define FORT_H

#include "Building.h"
#include "Attacker.h"
#include "Unit.h"

class Fort : public Building, public IAttacker {
public:
	Fort() = default;
	
	Fort(int x, int y) { X = x; Y = y; }

	std::string getName() { return "Fort"; }

	int getX() { return X; }

	int getY() { return Y; }

	void attack(Unit& unit) {
		unit.receiveDamage(dmg_);
	}

	float getDamage() const {
		return dmg_;
	}
private:
	int X = 0;
	int Y = 0;
	float dmg_ = 25;
};

#endif // !FORT_H
