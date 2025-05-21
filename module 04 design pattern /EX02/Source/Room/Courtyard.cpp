#include "../../Header/Room.hpp"

Courtyard::Courtyard() : Room()
{
	std::cout << "Courtyard created\n";
	_type = "Courtyard";
}

Courtyard::~Courtyard()
{
	std::cout << "Courtyard destroyed\n";
}