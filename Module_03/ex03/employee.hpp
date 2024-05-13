#ifndef __EMPLOYEE_HPP__

#define __EMPLOYEE_HPP__

#include <iostream>



class Employee
{
    protected:
    Employee() {}
    std::string _name;
    int _salary;
    int _hourlyvalue;
    int _TravelTime;

    public:
    int getSalary() { return _salary; }
    Employee(std::string name, int hourlyvalue) : _name(name), _hourlyvalue(hourlyvalue), _TravelTime(0), _salary(0) {}
    
    std::string getName() { return _name; }
    int getHourlyValue() { return _hourlyvalue; }
    void setHourlyValue(int hourlyvalue) { _hourlyvalue = hourlyvalue; }
    virtual ~Employee() {}
    virtual int executeWorkday()  = 0;

};


#endif // __EMPLOYEE_HPP__