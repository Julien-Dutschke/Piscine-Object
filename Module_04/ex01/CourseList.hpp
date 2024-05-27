#ifndef __COURSELIST_HPP__
#define __COURSELIST_HPP__

#include "AList.hpp"
#include "Course.hpp"

class CourseList : public AList<Course, CourseList>
{
    private:
    CourseList() : AList<Course, CourseList>("Course List") {}
    CourseList(std::string name) : AList<Course, CourseList>(name) {}
    
    public:
     std::string getName() const { return _name; }
};

#endif2