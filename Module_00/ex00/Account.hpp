#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>

class Account
{
    private:
    static int _nextId;
    int _id;
    int _value;
    
   public:
   Account();
   Account(int value);

   public:
   int getId() const;
   int getValue() const;
   friend class Bank;
   friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};

#endif