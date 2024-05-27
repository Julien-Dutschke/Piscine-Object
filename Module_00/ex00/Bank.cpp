#include "Bank.hpp"
#include <signal.h>
#define CLEAR_TERMINAL "\033[2J\033[1;1H"

int Bank::Account::_nextId = 0;
Bank& Bank::operator=(int)
{
    return *this;
}

void Bank::printBank() const
{
    std::cout << "--------------------------------\n";
    std::cout << "Bank balance : " << _balance << std::endl;
    for (std::vector<Account>::const_iterator it = _listAccounts.begin(); it != _listAccounts.end(); ++it)
    {
       it->printAccount();
    }
    std::cout << "--------------------------------\n";
}

void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

void Bank::startSimulation()
{
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    std::cout << CLEAR_TERMINAL;
    while(42)
    {
        std::cout << "Welcome to BeerBank\n";
        std::cout << "--------------------------------\n";
        std::cout << "[1] Add account       [2] Delete account\n";
        std::cout << "[3] Add money         [4] Remove money\n";
        std::cout << "[5] Give loan\n";
        std::cout << "--------------------------------\n";
        printBank();
        int choice = 0;
        switch (choice = std::cin.get())
        {
            case '1':
            {
                std::string name;
                std::cout << "Enter the name of the account : ";
                std::cin >> name;
                addAccount(name);
                break;
            }
            case '2':
            {
                int id;
                std::cout << "Enter the id of the account : ";
                std::cin >> id;
                deleteAccount(id);
                break;
            }
            case '3':
            {
                int id;
                int money;
                std::cout << "Enter the id of the account : ";
                std::cin >> id;
                std::cout << "Enter the amount of money : ";
                std::cin >> money;
                addMoneyAccount(id, money);
                break;
            }
            case '4':
            {
                int id;
                int money;
                std::cout << "Enter the id of the account : ";
                std::cin >> id;
                std::cout << "Enter the amount of money : ";
                std::cin >> money;
                removeMoneyAccount(id, money);
                break;
            }
            case '5':
            {
                int id;
                int money;
                std::cout << "Enter the id of the account : ";
                std::cin >> id;
                std::cout << "Enter the amount of money : ";
                std::cin >> money;
                giveLoan(id, money);
                break;
            }
            default:
            {
                std::cout << "Invalid choice\n";
                break;
            }
        }
        if (std::cin.eof())
        {
            break;
        }
        std::cout << "Press Any Key to Continue\n";
        std::cin.get();
        std::cout << CLEAR_TERMINAL;
    }
}

Bank::Bank() : _balance(42000)
{
    std::cout << "BeerBank constructed by Tolkgrim" << std::endl;
}

Bank& Bank::getInstance()
{
    static Bank instance;
    return instance;
}

Bank::Account Bank::operator[](int id) const
{
    for (std::vector<Account>::const_iterator it = _listAccounts.begin(); it != _listAccounts.end(); ++it)
    {
        if (it->getId() == id)
        {
            return *it;
        }
    }
    throw std::exception();
}

void Bank::addAccount(std::string name)
{
    _listAccounts.push_back(Account(name));
}

void Bank::deleteAccount(int id)
{
    for (std::vector<Account>::iterator it = _listAccounts.begin(); it != _listAccounts.end(); ++it)
    {
        if (it->getId() == id)
        {
            _listAccounts.erase(it);
            break;
        }
    }
}

void Bank::addMoneyAccount(int id, int money)
{
    if (money < 0)
    {
        std::cout << "You can't add negative money" << std::endl;
        return;
    }
    for (std::vector<Account>::iterator it = _listAccounts.begin(); it != _listAccounts.end(); ++it)
    {
        if (it->getId() == id)
        {
            it->_balance = (it->getBalance() + (money * 0.95));
            _balance += money * 0.05;
            return;
        }
    }
}

void Bank::removeMoneyAccount(int id, int money)
{
    if (money < 0)
    {
        std::cout << "You can't remove negative money" << std::endl;
        return;
    }
    for (std::vector<Account>::iterator it = _listAccounts.begin(); it != _listAccounts.end(); ++it)
    {
        if (it->getId() == id)
        {
            if (it->getBalance() < money)
            {
                std::cout << "Not enough money" << std::endl;
                return;
            }
            it->_balance =(it->getBalance() - money);
            return;
        }
    }
}

void Bank::giveLoan(int id, int money)
{
    if (money < 0)
    {
        std::cout << "You can't give negative money" << std::endl;
        return;
    }
    for (std::vector<Account>::iterator it = _listAccounts.begin(); it != _listAccounts.end(); ++it)
    {
        if (it->getId() == id)
        {
            it->_balance = (it->getBalance() + money);
            _balance -= money;
            return;
        }
    }
}

