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
	for (Student *student : _items)
	{
		std::cout << student->getName() << std::endl;
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

