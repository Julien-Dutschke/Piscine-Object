
#include "employeeManagement.hpp"
#include "employee.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main()
{
    EmployeeManagement management;

    Employee* emp1 = new TempWorker("John", 9, 5);

    management.addEmployee(emp1);

    for (int i = 0; i < 20; i++)
    {
        management.executeWorkday();
    }

    management.calculatePayroll();

}