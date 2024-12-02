// TP_Lab4.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#define STRATEGY_H

#include <iostream>
#include <string>

class ShippingStrategy {
public:
    virtual double calculateShippingCost(double weight, double distance) = 0;
    virtual ~ShippingStrategy() {}
};


class YandexShipping : public ShippingStrategy {
public:
    double calculateShippingCost(double weight, double distance) override {
        return weight * 5.0 + distance * 2.0;
    }
};

class MoscowShipping : public ShippingStrategy {
public:
    double calculateShippingCost(double weight, double distance) override {
        double cost = weight * 1.2;
        if (distance > 40.0) {
            cost += (distance - 40) * 7;
        }
        return cost;
    }
};

class SberShipping : public ShippingStrategy {
public:
    double calculateShippingCost(double weight, double distance) override {
        double cost = weight * 10.0 + distance * 1.2;
        return cost > 150.0 ? cost : 150.0;
    }
};

class Order {
public:
    Order(double weight, double distance) : weight(weight), distance(distance), shippingStrategy(nullptr) {}

    void setShippingStrategy(ShippingStrategy* shippingStrategy) {
        this->shippingStrategy = shippingStrategy;
    }

    double calculateTotalCost() {
        if (shippingStrategy) {
            return shippingStrategy->calculateShippingCost(weight, distance);
        }
        else {
            std::cout << "Please set a shipping method." << std::endl;
            return 0.0;
        }
    }
    ~Order() {
        if (shippingStrategy) {
            delete shippingStrategy;
        }
    }
private:
    ShippingStrategy* shippingStrategy;
    double weight;
    double distance;
};