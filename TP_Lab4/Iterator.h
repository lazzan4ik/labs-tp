#pragma once
#define ITERATOR_H

#include <iostream>

template<typename T> class Iterator {
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

template<typename T> class ConcreteIterator : public Iterator<T> {
public:
    ConcreteIterator(T* collection, int size) : collection(collection), index(0), size(size) {};

    bool hasNext() {
        return index < size - 1;
    }

    T next() {
        if (this->hasNext()) {
            return collection[index++];
        }
        else {
            std::cout << "Next does not exist" << std::endl;
        }
    }

private:
    T* collection;
    int index;
    int size;
};