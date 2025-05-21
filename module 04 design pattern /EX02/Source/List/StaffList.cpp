#include "../../Header/List.hpp"

#include "../../Header/Person.hpp"

StaffList::StaffList()
{
	std::cout << "StaffList created\n";
}

StaffList::~StaffList()
{
	std::cout << "StaffList destroyed\n";
}

void StaffList::display() const
{
	std::cout << "number of staff: " << _items.size() << std::endl;
	std::list<Person>::const_iterator it;
		std::cout << "StaffList::display() called\n";
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		std::cout << "Staff: " << it->getName() << std::endl;
	}
}