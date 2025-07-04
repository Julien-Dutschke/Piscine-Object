#include "../../Header/List.hpp"

StudentList::StudentList()
{
}

StudentList::~StudentList()
{
    for (auto it = _items.begin(); it != _items.end(); )
	{
        delete *it;
        it = _items.erase(it);
    }
}

void StudentList::display() const 
{
	std::cout << "number of students: " << _items.size() << std::endl;
	std::cout << "StudentList::display() called\n";
	
	for (Student *student : _items)
	{
		std::cout << "Student: " << student->getName() << std::endl;
	}	
}

Student* StudentList::getStudent(const std::string& name)
{
	for (Student *student : _items)
	{
		if (student->getName() == name)
		{
			return student;
		}
	}
	return nullptr;
}

