#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"
#include "Moveable.h"
#include "Attacker.h"

class Archer: public Unit, public IMoveable, public IAttacker {
public:
	inline Archer() = default;

	inline Archer(int x, int y) {
		X = x;
		Y = y;
	}

	int getMaxMove() const {
		return maxMove;
	}

	float getDamage() const {
		return dmg_;
	}

	void attack(Unit& unit) override {
		unit.receiveDamage(this->getDamage());
	}

	/*void move(int x, int y) {
		if (x + y > this->getMaxMove()) {
			std::cout << "Not correct move" << std::endl;
		}
		else {
			X += x;
			Y += y;
		}
	}*/

	int getX() {
		return X;
	}

	int getY() {
		return Y;
	}

	std::string getName() { return "Archer"; }
private:
	int dmg_ = 10;
	int maxMove = 7;
};


#endif // !UNIT_H