#ifndef __STAFFLIST_HPP__
#define __STAFFLIST_HPP__

#include "AList.hpp"

#include "Staff.hpp"

#include <vector>

class StaffList : public AList<Staff, StaffList>
{
    private:
    StaffList() : AList<Staff, StaffList>("Staff List") {}
    StaffList(std::string name) : AList<Staff, StaffList>(name) {}
    
    public:
     std::string getName() const { return _name; }
};

#endif