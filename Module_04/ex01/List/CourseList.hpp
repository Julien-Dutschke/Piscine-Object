#ifndef __COURSELIST_HPP__
#define __COURSELIST_HPP__

#include "../Course.hpp"
#include "../Patern/Singletons.hpp"
#include <list>
#include "ListPrinter.hpp"


class CourseList : public std::list<Course*>, public Singletons<CourseList>, public ListPrinter
{

    private:
    friend class Singletons<CourseList>;

    private:
        CourseList(){};
        CourseList(std::string name) = delete;
        CourseList(const CourseList& other) = delete;

    public:

};


#endif