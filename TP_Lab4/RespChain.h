#pragma once
#define RESPCHAIN_H

#include <iostream>

class DiscountHandler {
public:
    DiscountHandler(DiscountHandler* next = nullptr) : next_(next) {}

    virtual ~DiscountHandler() = default;
    virtual double applyDiscount(double price) {
        if (next_ != nullptr) {
            return next_->applyDiscount(price);
        }
        return price;
    }

protected:
    DiscountHandler* next_;
};

class AmountDiscountHandler : public DiscountHandler {
public:
    AmountDiscountHandler(DiscountHandler* next = nullptr) : DiscountHandler(next) {}

    double applyDiscount(double price) override {
        if (price > 1000) {
            std::cout << "Applying 5% discount for price > 1000 rub" << std::endl;
            price *= 0.95;
        }
        return DiscountHandler::applyDiscount(price); //передача обработки следующему
    }
};

class RegularDiscountHandler : public DiscountHandler {
public:
    RegularDiscountHandler(DiscountHandler* next = nullptr) : DiscountHandler(next) {}
    double applyDiscount(double price) override {
        std::cout << "Applying 10% discount for being the Regular Customer" << std::endl;
        price *= 0.9;
        return DiscountHandler::applyDiscount(price);  //передача обработки следующему
    }
};