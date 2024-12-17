#pragma once

#include <iostream>
#include <string>

class BankAccount {
public: 
    virtual void deposit(double dep) = 0;
    virtual void withdraw(double dep) = 0;
    virtual double getBalance() = 0;
    virtual ~BankAccount() {}
};

class RealBankAccount : public BankAccount {
private: 
    double balance = 0;

public: 
    RealBankAccount() = default;
    RealBankAccount(double balance) : balance(balance) {};

    void deposit(double dep) override {
        if (dep > 0) {
            balance += dep;
            std::cout << "Succesfully deposited: " << dep << ". Your balance now is: " << balance << std::endl;
        }
        else {
            std::cout << "Error occured while depositing" << std::endl;
        }
    }

    void withdraw(double dep) override {
        if (dep <= 0) {
            std::cout << "Error occured while withdrawing" << std::endl;
            return;
        }
        balance -= dep;
        std::cout << "Succesfully withdrawed: " << dep << ". Your balance now is: " << balance << std::endl;
    }

    double getBalance() override {
        return balance;
    }
};

class BankAccountProxy : public BankAccount {
private:
    RealBankAccount* realAccount;
    std::string password;

public:
    BankAccountProxy(double initialBalance, const std::string& password) :
        realAccount(new RealBankAccount(initialBalance)), password(password) {}

    bool checkAccess(const std::string& enteredPassword) {
        return enteredPassword == password;
    }

    void deposit(double dep) override {
        std::string enteredPassword;
        std::cout << "Enter password: ";
        std::cin >> enteredPassword;

        if (checkAccess(enteredPassword)) {
            realAccount->deposit(dep);
        }
        else {
            std::cout << "Access denied!" << std::endl;
        }
    }

    void withdraw(double dep) override {
        std::string enteredPassword;
        std::cout << "Enter password: ";
        std::cin >> enteredPassword;

        if (checkAccess(enteredPassword)) {
            realAccount->withdraw(dep);
        }
        else {
            std::cout << "Access denied!" << std::endl;
        }
    }

    double getBalance() override {
        std::string enteredPassword;
        std::cout << "Enter password: ";
        std::cin >> enteredPassword;

        if (checkAccess(enteredPassword)) {
            return realAccount->getBalance();
        }
        else {
            std::cout << "Access denied!" << std::endl;
            return -1; // Возвращаем -1, чтобы показать ошибку доступа
        }
    }

    ~BankAccountProxy() {
        delete realAccount;
    }
};

