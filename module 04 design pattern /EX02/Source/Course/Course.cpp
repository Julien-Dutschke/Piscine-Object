#include "../../Header/Course.hpp"
#include "iostream"

Course::Course(std::string p_name) : _name(p_name), _professor(nullptr), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
	std::cout << "Course created\n";
}

void Course::assign(Professor* p_professor)
{
	_professor = p_professor;     
	_numberOfClassToGraduate = 0;                                                                                                                                                                                                                                                                                                                                                     
}

std::string Course::getName() const
{
	return _name;
}

Professor* Course::getProfessor() const
{
	return _professor;
}

void Course::subscribe(Student* p_student)
{
	if (_students.size() < _maximumNumberOfStudent)
	{
		_students.push_back(p_student);
	}
}
bool Course::operator==(const Course& p_course) const
{
	return _name == p_course._name;
}

Course::~Course()
{
	std::cout << "Course destroyed\n";
}