#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include <vector>

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

#endif // __STUDENT_HPP