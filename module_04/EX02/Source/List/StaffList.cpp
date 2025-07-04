#include "../../Header/List.hpp"

#include "../../Header/Person.hpp"

StaffList::StaffList()
{
}

StaffList::~StaffList()
{
    for (auto it = _items.begin(); it != _items.end(); )
	{
        delete *it;
        it = _items.erase(it);
    }
}

void StaffList::display() const
{
	std::cout << "number of staff: " << _items.size() << std::endl;
	std::cout << "StaffList::display() called\n";
	for (const Person* person : _items)
	{
		std::cout << "Staff: " << person->getName() << std::endl;
	}
}