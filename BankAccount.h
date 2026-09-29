//
// Created by CSStudent on 9/15/2026.
//

#ifndef UNTITLED_BANKACCOUNT_H
#define UNTITLED_BANKACCOUNT_H

#include <iostream>
class BankAccount {
    public:
        BankAccount();
        BankAccount(const BankAccount&);

        ~BankAccount();

        BankAccount& operator=(const BankAccount&);
        BankAccount& operator+=(double amount);
        BankAccount& operator-=(double amount);

        bool operator==(const BankAccount& other);
        bool operator<(const BankAccount& other);
        bool operator>(const BankAccount& other);

        std::string getAccountNumber();
        std::string getAccountHolderName();
        double getBalance();

        void setAccountHolderName(const std::string &);

        void deposit(double);
        double withdraw(double);
        void void_withdraw(double amount);

        static void print_details(const BankAccount &acc);
        static BankAccount createAccountFromInput();

        static int NEXT_ID;
    private:
        std::string acc_num, acc_holder_name;
        double balance;

        void setAccountNumber(const std::string&);
        void setBalance(double);
};

#endif //UNTITLED_BANKACCOUNT_H
