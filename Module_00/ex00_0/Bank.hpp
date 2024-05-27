#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <iostream>
#include <vector>
#include <string>



class Bank
{
    private:
    Bank& operator=(int);
    //! Account class
    class Account
    {
        private:
        int _id;
        std::string _name;
        static int _nextId;
        int _balance;
        friend class Bank;

        public:
        Account(std::string name);
        void printAccount() const;
        int getBalance() const;
        int getId() const;
    };

    private:
    int _balance;
    std::vector<Account> _listAccounts;
    Bank();


    public:
    //!Singetons pattern
    Bank& getInstance();
    void addAccount(std::string name);
    void deleteAccount(int id);
    void addMoneyAccount(int id, int money);
    void startSimulation();
    void giveLoan(int id, int money);
    void removeMoneyAccount(int id, int money);
    Account operator[](int id) const;
    void printBank() const;
};

int Bank::Account::_nextId = 0;

#endif