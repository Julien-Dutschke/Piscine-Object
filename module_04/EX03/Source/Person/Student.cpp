#include "../../Header/Person.hpp"
#include "../../Header/Room.hpp"

Student::Student()
{
	std::cout << "Student created\n";
}

Student::Student(std::string name) : Person("Student "+name)
{
}


void Student::attendClass(Classroom* p_classroom)
{
	_currentRoom = p_classroom;
	std::cout << "Student attend class\n";
}

void Student::exitClass()
{
	_currentRoom = nullptr;
	std::cout << "Student exit class\n";
}

void Student::graduate(Course* p_course)
{
	_subscribedCourse.push_back(p_course);
	std::cout << "Student graduated\n";
}

void Student::leaveCourse(Course* p_course)
{
	for (size_t i = 0; i < _subscribedCourse.size(); i++)
	{
		if (_subscribedCourse[i] == p_course)
		{
			_subscribedCourse.erase(_subscribedCourse.begin() + i);
			std::cout << "Student left course\n";
			return;
		}
	}
	std::cout << "Student not subscribed to course\n";
}