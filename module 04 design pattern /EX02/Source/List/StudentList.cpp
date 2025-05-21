#include "../../Header/List.hpp"

StudentList::StudentList()
{
	std::cout << "StudentList created\n";
}

StudentList::~StudentList()
{
	std::cout << "StudentList destroyed\n";
}

void StudentList::display() const 
{
	std::cout << "number of students: " << _items.size() << std::endl;
	std::list<Student>::const_iterator it;
		std::cout << "StudentList::display() called\n";
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		std::cout << "Student: " << it->getName() << std::endl;
	}	
}

