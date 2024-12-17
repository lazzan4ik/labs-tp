#pragma once

#include <iostream>

class BankAccount {
private:
	std::string accountNumber;
	float balance = 0.0;
public:
	BankAccount(std::string acc) : accountNumber(acc) {};
	BankAccount(std::string acc, float bal) {
		if (bal < 0) {
			throw std::exception("Such account can not exist");
			return;
		}
		balance = bal;
		accountNumber = acc;
	}
	~BankAccount() { balance = 0; accountNumber = ""; }

	void deposit(float amount) {
		if (amount <= 0) {
			throw std::exception("Invalid amount to deposit");
			return;
		}
		balance += amount;
	}

	void withdraw(float amount) {
		if (amount <= 0 || balance < amount) {
			throw std::exception("Invalid amount to withdraw");
			return;
		}
		balance -= amount;
	}

	float getBalance() const {
		return balance;
	}
};
