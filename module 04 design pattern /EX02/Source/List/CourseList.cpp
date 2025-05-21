#include "../../Header/List.hpp"

#include "../../Header/Course.hpp"

CourseList::CourseList()
{
	std::cout << "CourseList created\n";
}

CourseList::~CourseList()
{
	std::cout << "CourseList destroyed\n";
}

void CourseList::display() const 
{
	std::cout << "number of courses: " << _items.size() << std::endl;
	std::list<Course>::const_iterator it;
		std::cout << "CourseList::display() called\n";
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		std::cout << "Course: " << it->getName() << std::endl;
	}	
}