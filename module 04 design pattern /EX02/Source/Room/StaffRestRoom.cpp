#include "../../Header/Room.hpp"


StaffRestRoom::StaffRestRoom() : Room()
{
	std::cout << "StaffRestRoom created\n";
	_type = "StaffRestRoom";
}

StaffRestRoom::~StaffRestRoom()
{
	std::cout << "StaffRestRoom destroyed\n";
}