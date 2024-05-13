#ifndef __EMPLOYEEMANAGEMENT_HPP__
#define __EMPLOYEEMANAGEMENT_HPP__

#include <unistd.h>
#include <iostream>
#include "employee.hpp"
#include <vector>

class EmployeeManagement
{
    private:
    std::vector<Employee*> _listEmployee;

    public:
    void addEmployee(Employee* user)
    {
        _listEmployee.push_back(user);
    }

    void removeEmployee(Employee* user)
    {
        for (std::vector<Employee*>::iterator it = _listEmployee.begin(); it != _listEmployee.end(); ++it)
        {
            if (*it == user)
            {
                _listEmployee.erase(it);
                break;
            }
        }
    }

    void calculatePayroll()
    {
        int total = 0;
        for (std::vector<Employee*>::iterator it = _listEmployee.begin(); it != _listEmployee.end(); ++it)
        {
            std::cout << "Employee: " << (*it)->getName() << " has a salary of " << (*it)->getSalary() << std::endl;
            total += (*it)->getSalary();
        }
        std::cout << "Total payroll: " << total << std::endl;
    }

    void executeWorkday()
    {
        for (std::vector<Employee*>::iterator it = _listEmployee.begin(); it != _listEmployee.end(); ++it)
           (*it)->executeWorkday();
    
    }
};

#endif // __EMPLOYEEMANAGEMENT_HPP__