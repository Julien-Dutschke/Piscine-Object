#include "../../Header/Person.hpp"

bool Person::operator==(const Person& p_person) const
{
	return this == &p_person;
}

std::string Person::getName() const
{
	return _name;
}

void Person::setName(std::string p_name)
{
	_name = p_name;
}

Person::Person()
{
	std::cout << "Person created\n";
}

Person::Person(const std::string& name) : _name(name), _currentRoom(nullptr)
{
	std::cout << "Person created\n";
}
Person::~Person()
{
	std::cout << "Person destroyed\n";
}

