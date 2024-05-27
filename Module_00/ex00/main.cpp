#include "Bank.hpp"

int main()
{
    Bank bank = Bank::getInstance();
    bank.startSimulation();

    return 0;
}