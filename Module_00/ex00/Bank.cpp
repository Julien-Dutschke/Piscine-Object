#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() : _liquidity(0)
{
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
    std::vector<Account *>::const_iterator it = p_bank._clientAccounts.begin();
    std::vector<Account *>::const_iterator ite = p_bank._clientAccounts.end();
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
    for (; it != ite; it++)
    {
        p_os << **it << std::endl;
    }
    return (p_os);
}


int Bank::getLiquidity() const
{
    return (_liquidity);
}

void Bank::setLiquidity(int liquidity)
{
    _liquidity = liquidity;
}

std::vector<Account *> Bank::getClientAccounts() const
{
    return (_clientAccounts);
}

void Bank::removeAccount(Account *account)
{
    std::vector<Account *>::iterator it = _clientAccounts.begin();
    std::vector<Account *>::iterator ite = _clientAccounts.end();
    for (; it != ite; it++)
    {
        if ((*it)->getId() == account->getId())
        {
            _clientAccounts.erase(it);
            return;
        }
    }
}

void Bank::addAccount(Account *account)
{
    std::vector<Account *>::iterator it = _clientAccounts.begin();
    std::vector<Account *>::iterator ite = _clientAccounts.end();
    for (; it != ite; it++)
    {
        if ((*it)->getId() == account->getId())
            return;
    }
    _clientAccounts.push_back(account);
}

void Bank::giveLoan(Account *account, int value)
{
    if (value > _liquidity)
        return;
    _liquidity -= value;
    account->_value += value;
}

void Bank::giveLoan(int id, int value)
{
    std::vector<Account *>::iterator it = _clientAccounts.begin();
    std::vector<Account *>::iterator ite = _clientAccounts.end();
    for (; it != ite; it++)
    {
        if ((*it)->getId() == id)
        {
            if (value > _liquidity)
                return;
            _liquidity -= value;
            (*it)->_value += value;
            return;
        }
    }
}

void Bank::addAccountValue(int id, int value)
{
    std::vector<Account *>::iterator it = _clientAccounts.begin();
    std::vector<Account *>::iterator ite = _clientAccounts.end();
    for (; it != ite; it++)
    {
        if ((*it)->getId() == id)
        {
            _liquidity += (value * 0.05);
            (*it)->_value += (value * 0.95);
            return;
        }
    }
}

void Bank::addAccountValue(Account *account, int value)
{
    _liquidity += (value * 0.05);
    account->_value += (value * 0.95);
}

Bank &Bank::operator-=(int value)
{
    _liquidity -= value;
    return (*this);
}

Bank &Bank::operator+=(int value)
{
    _liquidity += value;
    return (*this);
}

void Bank::decreaseAccountValue(int id, int value)
{
    std::vector<Account *>::iterator it = _clientAccounts.begin();
    std::vector<Account *>::iterator ite = _clientAccounts.end();
    for (; it != ite; it++)
    {
        if ((*it)->getId() == id)
        {
            (*it)->_value -= value;
            return;
        }
    }
}

void Bank::decreaseAccountValue(Account *account, int value)
{
    account->_value -= value;
}

// Path: ex00/Account.cpp