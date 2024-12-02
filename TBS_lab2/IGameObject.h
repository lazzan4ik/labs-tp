#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H
#include <string>

class IGameObject {
public:
	inline IGameObject() { ObjectId = NextObjectId++; }

	inline int getId() { return ObjectId; }

	virtual std::string getName() = 0;

	virtual int getX() = 0;

	virtual int getY() = 0;

private:
	int ObjectId;
	static int NextObjectId;
};;

int IGameObject::NextObjectId = 1;
#endif // !GAMEOBJECT_H