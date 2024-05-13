#ifndef __SALARIEDEMPLOYEE_HPP__

#define __SALARIEDEMPLOYEE_HPP__

#include <iostream>

#include "employee.hpp"



class SalariedEmployee : public Employee
{

    protected:
    int _hourOfAbsence;
    SalariedEmployee(){}

    public:
    SalariedEmployee(std::string name, int hourlyvalue) : Employee(name, hourlyvalue), _hourOfAbsence(0) {}
    int getHourOfAbsence() { return _hourOfAbsence;}
    
};


/*The ContractEmployee, on the other hand,
must register the hour it will NOT do
(Vacantion, sickness, any reason)*/

class ContractEmployee : public SalariedEmployee 
{
    protected:
    ContractEmployee(){}

    public:
    ContractEmployee(std::string name, int hourlyvalue) : SalariedEmployee(name, hourlyvalue) {}

    void setHourOfAbsence(int hourOfAbsence) { _hourOfAbsence = hourOfAbsence; }
    int executeWorkday(){
        _salary += _hourlyvalue * 7;
    return _hourlyvalue * 7;}
    int getHourOfAbsence() { return _hourOfAbsence;}

    int getSalary() { return _salary - (_hourOfAbsence * _hourlyvalue); }
};

/*like SalariedEmployee,
Apprentice need a way to indicate how many 
hours of school he will do before going
back to work. Those hours passed at school
will be payed half the hourly value*/

class Apprentice : public ContractEmployee
{
    private:
    int _hourOfSchool;
    Apprentice(){}

    public:
    Apprentice(std::string name, int hourlyvalue, int schoolTime) : ContractEmployee(name, hourlyvalue), _hourOfSchool(schoolTime) {}

    void setHourOfSchool(int hourOfSchool) { _hourOfSchool = hourOfSchool; }
    int executeWorkday()
    {
        _salary += ((7 -_hourOfSchool ) * _hourlyvalue) + (_hourOfSchool * _hourlyvalue / 2);
        return ((7 -_hourOfSchool ) * _hourlyvalue) + (_hourOfSchool * _hourlyvalue / 2);
    }
    int getHourOfSchool() { return _hourOfSchool;}

};


#endif // __SALARIEDEMPLOYEE_HPP__