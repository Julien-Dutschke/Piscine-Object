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
	for (const Person* person : _items)
	{
		std::cout << person->getName() << std::endl;
	}
}