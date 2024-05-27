#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>


class Bank
{
    private:
    Bank& operator=(int);
    //! Account class
    class Account
    {
        private:
        int _id;
        int _balance;
        std::string _name;
        static int _nextId;
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
    static Bank& getInstance();
    void addAccount(std::string name);
    void deleteAccount(int id);
    void addMoneyAccount(int id, int money);
    void startSimulation();
    void giveLoan(int id, int money);
    void removeMoneyAccount(int id, int money);
    Account operator[](int id) const;
    void printBank() const;
};

#endif