#ifndef UNIT_H
#define UNIT_H

#include "IGameObject.h"

class Unit: public IGameObject {
public:
	inline Unit() { hp = 100; }

	inline Unit(float HP) { hp = HP; }
	
	bool isAlive() { if (hp == 0) { return false; } else { return true; }; }

	const float getHp() { return hp; }

	virtual void receiveDamage(float damage) { this->hp -= damage; 
		if (hp < 0) { this->hp = 0; } 
	}

	virtual std::string getName() = 0;

	virtual int getX() = 0;

	virtual int getY() = 0;

protected:
	float hp = 100;
	virtual ~Unit() = default;
};


#endif // !UNIT_H