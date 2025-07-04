#include "../../Header/Person.hpp"
#include "../../Header/Course.hpp"

Professor::Professor() : Staff("Professor"), _currentCourse(nullptr)
{
}

Professor::Professor(std::string name) : Staff("Professor " + name), _currentCourse(nullptr)
{
}

Professor::~Professor()
{
}

void Professor::assignCourse(Course* p_course)
{
	if (p_course == nullptr)
	{
		std::cout << "Course is null\n";
		return;
	}
	_currentCourse = p_course;
	std::cout << "Course assigned\n";
}

void Professor::doClass()
{
	if (_currentCourse == nullptr)
	{
		std::cout << "Aucun cours n'est assigner\n";
		return;
	}
	//TODO : mettre en place la logique de cours
	std::cout << "Lancement du cours :" << _currentCourse->getName() << "\n";
}

void Professor::closeCourse()
{
	if (_currentCourse == nullptr)
	{
		std::cout << "No course assigned\n";
		return;
	}
	std::cout << "Closing course: " << _currentCourse->getName() << "\n";
	_currentCourse = nullptr;
}

void Professor::setCourse(Course* p_course)
{
	_currentCourse = p_course;
}