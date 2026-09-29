//
// Created by CSStudent on 9/15/2026.
//

/*
*
*   For some weird reason
*   I dont see any option to write documentation, and i looked through some menus to no avail
*   I am not really sure what to do and I, in all honesty, really dont want to type it all myself.
*   I am just admitting to being lazy here, but I'd expect the tool I am supposed to be using to work, and it isn't,
*   ..so I'll just leave this notice here and I'll try again tomorrow.
*
*   9/29/26
*
*/


#include "BankAccount.h"

BankAccount::BankAccount() {
    this->acc_num = NEXT_ID;
    this->acc_holder_name = "EMPTY";
    this->balance = 0.0;

    NEXT_ID++;
}
BankAccount::BankAccount(const BankAccount& other) {
    this->acc_num = other.acc_num;
    this->acc_holder_name = other.acc_holder_name;
    this->balance = other.balance;
}

int BankAccount::NEXT_ID = 0;

BankAccount::~BankAccount() {}

std::string BankAccount::getAccountNumber() {
    return this->acc_num;
}
std::string BankAccount::getAccountHolderName() {
    return this->acc_holder_name;
}
double BankAccount::getBalance() {
    return this->balance;
}

void BankAccount::setAccountHolderName(const std::string& acc_name) {
    this->acc_holder_name = acc_name;
}
void BankAccount::setAccountNumber(const std::string& acc_num) {
    this->acc_num = acc_num;
}
void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

void BankAccount::deposit(double amount) {
    if (amount <= 0.0) {
        std::cout << "The balance deposited was not positive.\nDeposit canceled." << std::endl;
        return;
    }
    this->balance += amount;
}
double BankAccount::withdraw(double amount) {
    double current_balance = this->balance;
    double balance_taken = amount;

    if (current_balance > amount) {
        std::cout << "The amount is greater than the account balance.\nWithdraw canceled." << std::endl;
        return 0.0;
    }
    if (amount < 0.0) {
        std::cout << "Invalid amount to withdraw.\nWithdraw canceled." << std::endl;
        return 0.0;
    }

    this->balance -= amount;
    return balance_taken;
}
void BankAccount::void_withdraw(double amount) {
    double current_balance = this->balance;

    if (current_balance > amount) {
        std::cout << "The amount is greater than the account balance.\nWithdraw canceled." << std::endl;
        return;
    }
    if (amount < 0.0) {
        std::cout << "Invalid amount to withdraw.\nWithdraw canceled." << std::endl;
        return;
    }

    this->balance -= amount;
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        this->acc_num = other.acc_num;
        this->acc_holder_name = other.acc_holder_name;
        this->balance = other.balance;
    }
    return *this;
}

BankAccount& BankAccount::operator+=(double amount) {
    BankAccount modified_acc = *this;

    modified_acc.deposit(amount);
    return modified_acc;
}

BankAccount& BankAccount::operator-=(double amount) {
    BankAccount modified_acc = *this;

    modified_acc.void_withdraw(amount);
    return modified_acc;
}

bool BankAccount::operator==(const BankAccount &other) {
    return (acc_num == other.acc_num);
}
bool BankAccount::operator<(const BankAccount &other) {
    return (balance < other.balance);
}
bool BankAccount::operator>(const BankAccount &other) {
    return (balance > other.balance);
}




void BankAccount::print_details(const BankAccount &acc) {
    std::cout << acc.acc_holder_name << "'s Account:\n"
                 "#:        " << acc.acc_num << "\n"
                 "Balance:  " << acc.balance << "\n" << std::endl;
}

BankAccount BankAccount::createAccountFromInput() {
    std::string name, acc_num = std::to_string(NEXT_ID);
    double balance;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter balance: " << std::endl;
    std::cin >> balance;

    BankAccount acc;
    acc.setAccountNumber(acc_num);
    acc.setBalance(balance);
    acc.setAccountHolderName(name);

    print_details(acc);

    return acc;
}
