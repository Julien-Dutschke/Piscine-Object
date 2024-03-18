#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <iostream>
#include <vector>

class Account; 

class Bank{

    private :
    int _liquidity;
    std::vector<Account *> _clientAccounts;

    public :
    Bank();

    public :
    void addAccount(Account *account);
    void addAccountValue(int id, int value);
    void addAccountValue(Account *account, int value);
    void decreaseAccountValue(int id, int value);
    void decreaseAccountValue(Account *account, int value);
    void removeAccount(Account *account);
    int getLiquidity() const;
    void giveLoan(Account *account, int value);
    void giveLoan(int id, int value);
    void setLiquidity(int liquidity);
    std::vector<Account *> getClientAccounts() const;
    
    friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
    Bank &operator-=(int value);
    Bank &operator+=(int value);
};


#endif