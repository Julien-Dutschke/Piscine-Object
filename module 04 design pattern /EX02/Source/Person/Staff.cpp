#include "../../Header/Person.hpp"
#include "../../Header/Form.hpp"

Staff::Staff() : Person("Staff")
{
	std::cout << "Staff created\n";
}

Staff::Staff(std::string name) : Person(name)
{
	std::cout << "Staff copy created\n";
}

Staff::~Staff()
{
	std::cout << "Staff destroyed\n";
}

