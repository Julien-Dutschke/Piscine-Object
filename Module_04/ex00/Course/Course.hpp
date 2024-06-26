#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include <iostream>
#include "../Person/StaffMember/StaffMember.hpp"

enum class e_CourseType
{
    ENGLISH,
    MATH,
    SCIENCE,
    HISTORY,
    GEOGRAPHY,
    FRENCH,
    PHYSICAL_EDUCATION,
    ARTS,
    MUSIC,
    TECHNOLOGY
};

class Course
{
    private:
    e_CourseType _courseType;
    Professor* _professor;
    std::vector<Student*> _studentsList;
    int _numberOfClassToGraduate;
    int _maximumNumberOfStudent;


    public:
    Course(e_CourseType p_courseType) : _courseType(p_courseType){}
    bool assign(Professor* p_professor);
    bool subscribe(Student* p_student);
    bool isInCourse(Student* p_student);
};


#endif