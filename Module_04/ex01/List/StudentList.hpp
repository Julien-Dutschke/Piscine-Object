#ifndef __STUDENTLIST_HPP__
#define __STUDENTLIST_HPP__

#include "../Student.hpp"
#include <list>
#include "../Patern/Singletons.hpp"
#include "ListPrinter.hpp"

class StudentList : public std::list<Student*>, public Singletons<StudentList>, public ListPrinter
{
    private:
    friend class Singletons<StudentList>;

    private:
        StudentList(){}
        StudentList(std::string name) = delete;
        StudentList(const StudentList& other) = delete;

    public:

};


#endif