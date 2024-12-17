// TP_Lab6.cpp: определяет точку входа для приложения.
//

#include "BankAccount.h"
#include <gtest/gtest.h>

// Тест конструктора с только номером аккаунта
TEST(BankAccountTest, ConstructorWithAccountNumber) {
    std::string accNum = "123456789";
    BankAccount account(accNum);
    EXPECT_EQ(account.getBalance(), 0.0f);
}

// Тест конструктора с номером аккаунта и положительным балансом
TEST(BankAccountTest, ConstructorWithAccountNumberAndPositiveBalance) {
    std::string accNum = "987654321";
    float initialBalance = 1000.0f;
    BankAccount account(accNum, initialBalance);
    EXPECT_EQ(account.getBalance(), initialBalance);
}

// Тест конструктора с негативным балансом должен выбрасывать исключение
TEST(BankAccountTest, ConstructorWithNegativeBalance) {
    std::string accNum = "1122334455";
    float initialBalance = -500.0f;
    EXPECT_THROW({
        BankAccount account(accNum, initialBalance);
        }, std::exception);
}

// Тест метода deposit с положительной суммой
TEST(BankAccountTest, DepositPositiveAmount) {
    BankAccount account("123");
    account.deposit(500.0f);
    EXPECT_EQ(account.getBalance(), 500.0f);
}

// Тест метода deposit с нулевой суммой должен выбрасывать исключение
TEST(BankAccountTest, DepositZeroAmount) {
    BankAccount account("123");
    EXPECT_THROW({
        account.deposit(0.0f);
        }, std::exception);
}

// Тест метода deposit с негативной суммой должен выбрасывать исключение
TEST(BankAccountTest, DepositNegativeAmount) {
    BankAccount account("123");
    EXPECT_THROW({
        account.deposit(-100.0f);
        }, std::exception);
}

// Тест метода withdraw с положительной суммой, не превышающей баланс
TEST(BankAccountTest, WithdrawValidAmount) {
    BankAccount account("123", 1000.0f);
    account.withdraw(400.0f);
    EXPECT_EQ(account.getBalance(), 600.0f);
}

// Тест метода withdraw с суммой превышающей баланс должен выбрасывать исключение
TEST(BankAccountTest, WithdrawAmountExceedingBalance) {
    BankAccount account("123", 300.0f);
    EXPECT_THROW({
        account.withdraw(500.0f);
        }, std::exception);
}

// Тест метода withdraw с нулевой суммой должен выбрасывать исключение
TEST(BankAccountTest, WithdrawZeroAmount) {
    BankAccount account("123", 300.0f);
    EXPECT_THROW({
        account.withdraw(0.0f);
        }, std::exception);
}

// Тест метода withdraw с негативной суммой должен выбрасывать исключение
TEST(BankAccountTest, WithdrawNegativeAmount) {
    BankAccount account("123", 300.0f);
    EXPECT_THROW({
        account.withdraw(-200.0f);
        }, std::exception);
}

// Тест метода getBalance
TEST(BankAccountTest, GetBalance) {
    BankAccount account("123", 750.0f);
    EXPECT_EQ(account.getBalance(), 750.0f);

    account.deposit(250.0f);
    EXPECT_EQ(account.getBalance(), 1000.0f);

    account.withdraw(500.0f);
    EXPECT_EQ(account.getBalance(), 500.0f);
}

// Главная функция для запуска всех тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
