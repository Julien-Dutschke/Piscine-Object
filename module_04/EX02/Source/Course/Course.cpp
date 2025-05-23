#include "../../Header/Course.hpp"
#include "../../Header/Person.hpp"
#include "iostream"

Course::Course(std::string p_name) : _name(p_name), _professor(nullptr), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
	// std::cout << "Course created\n";
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

//Pour arreter le cours

void Course::stop()
{
	//TODO : faire un formulaire de fin de cours
	std::cout << "Course stopped\n";

	_professor->setCourse(NULL);
	for (size_t i = 0; i < _students.size(); i++)
	{
		_students[i]->leaveCourse(this);
	}
	_students.clear();
	_professor = nullptr;
}

