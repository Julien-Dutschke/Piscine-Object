#ifndef __HOURLYEMPLOYEE_HPP__
#define __HOURLYEMPLOYEE_HPP__

#include <iostream>

#include "employee.hpp"


class hourlyEmployee : public Employee
{
    protected:
    hourlyEmployee() {}
    int _hourOfWork;

    public:
    hourlyEmployee(std::string name, int hourlyvalue, int WorkTime) : Employee(name, hourlyvalue){ setHourOfWork(WorkTime); }
    void setHourOfWork(int hour) { if (hour > 24 || hour <= 0) _hourOfWork = 1; else _hourOfWork = hour;}
    int getHourOfWork() { return _hourOfWork; }

};


/*The TempWorker is a class who must
register every work hour it will do. It is also
need a way to mobilise it over a certain
period of time, in hour.*/
class TempWorker : public hourlyEmployee
{
    private:
    TempWorker() {}

    public :
    TempWorker(std::string name, int hourlyvalue, int WorkTime) : hourlyEmployee(name, hourlyvalue, WorkTime) {}
    int executeWorkday()
    {
        _salary += _hourOfWork * _hourlyvalue;
        return _hourOfWork * _hourlyvalue;
    }

};

#endif // __HOURLYEMPLOYEE_HPP__ 