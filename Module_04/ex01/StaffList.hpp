#ifndef __STAFFLIST_HPP__
#define __STAFFLIST_HPP__

#include "Staff.hpp"
#include "Singletons.hpp"
#include <list>
#include "ListPrinter.hpp"


class StaffList : public std::list<Staff*>, public Singletons<StaffList>, public ListPrinter
{
    private:
    friend class Singletons<StaffList>;

    private :
        StaffList(){};
        StaffList(std::string name) = delete;
        StaffList(const StaffList& other) = delete;

    public :

};

#endif // __STAFFLIST_HPP