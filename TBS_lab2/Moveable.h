#ifndef IMOVEABLE_H
#define IMOVEABLE_H
#include <iostream>

class IMoveable {
public:
    inline IMoveable() { X = 0; Y = 0; };

    virtual int getMaxMove() const = 0;

    virtual void move(int x, int y) { 
        if (abs(x) + abs(y) > this->getMaxMove()) {
            std::cout << "Not correct move" << std::endl;
        }
        else {
            X += x;
            Y += y;
        }
    }
protected:
    virtual ~IMoveable() = default;
    int X;
    int Y;
};

#endif // !IMOVEABLE_H
