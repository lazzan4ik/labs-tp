#ifndef BUILDING_H
#define BUILDING_H

#include "IGameObject.h"

class Building : public IGameObject {
public:
	Building() = default;

	bool isBuilt() {
		return Built;
	}

	virtual std::string getName() = 0;

	virtual int getX() = 0;

	virtual int getY() = 0;

protected:
	bool Built = true;
};

#endif // !BUILDING_H
