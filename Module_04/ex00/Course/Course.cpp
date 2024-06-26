#include "Course.hpp"


bool Course::assign(Professor* p_professor)
{
    if (_professor == nullptr)
    {
        _professor = p_professor;
        return true;
    }
    else
        return false;
}

bool Course::isInCourse(Student* p_student)
{
    for (Student* student : _studentsList)
    {
        if (student == p_student)
            return true;
    }
    return false;
}

bool Course::subscribe(Student* p_student)
{
    if (_studentsList.size() < _maximumNumberOfStudent && isInCourse(p_student) == false)
    {
        _studentsList.push_back(p_student);
        return true;
    }
    else
        return false;
}