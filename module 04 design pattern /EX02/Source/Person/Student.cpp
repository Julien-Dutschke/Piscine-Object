#include "../../Header/Person.hpp"
#include "../../Header/Room.hpp"

Student::Student()
{
	std::cout << "Student created\n";
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