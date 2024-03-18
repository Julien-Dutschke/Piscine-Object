#include "Account.hpp"

Account::Account() : _id(_nextId++), _value(0){
}

Account::Account(int value) : _id(_nextId++), _value(value){
}

int Account::getId() const
{
    return _id;
}

int Account::getValue() const
{
    return _value;
}

std::ostream& operator<< (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
    return (p_os);
}


int Account::_nextId = 1;