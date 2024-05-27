#ifndef __STUDENTLIST_HPP__
#define __STUDENTLIST_HPP__

#include "AList.hpp"
#include "Student.hpp"
#include <vector>

class StudentList : public AList<Student, StudentList>
{
    private:
    StudentList() : AList<Student, StudentList>("Student List") {}
    StudentList(std::string name) : AList<Student, StudentList>(name) {}
    
    public:
    std::string getName() const { return _name; }
};


#endif