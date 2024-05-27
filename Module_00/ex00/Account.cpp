#include "Bank.hpp"

void Bank::Account::printAccount() const
{
    std::cout << "Account " << _id << " : " << _name << " : " << _balance << std::endl;
}

Bank::Account::Account(std::string name) : _id(_nextId++), 
                                           _balance(0), 
                                           _name(name){}


int Bank::Account::getBalance() const
{
    return _balance;
}

int Bank::Account::getId() const
{
    return _id;
}