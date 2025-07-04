#include "../../Header/Room.hpp"

Classroom::Classroom() : Room()
{
	std::cout << "Classroom created\n";
	_type = RoomType::ClassRoom;
	_currentCourse = nullptr;
}

Classroom::~Classroom()
{
	std::cout << "Classroom destroyed\n";
}

void Classroom::assignCourse(Course* p_course)
{
	_currentCourse = p_course;
	std::cout << "Course assigned to classroom\n";
}

