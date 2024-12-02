#ifndef MOBILEHOUSE_H
#define MOBILEHOUSE_H

#include "Building.h"
#include "Moveable.h"

class MobileHouse : public Building, public IMoveable {
public:
	std::string getName() { return "MobileHouse"; }

	int getX() {
		return X;
	}

	int getY() { return Y; }

	int getMaxMove() const { return maxMove; }
private:
	int maxMove = 3;

};

#endif // !MOBILEHOUSE_H
