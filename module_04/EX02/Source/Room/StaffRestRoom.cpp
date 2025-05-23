#include "../../Header/Room.hpp"


StaffRestRoom::StaffRestRoom() : Room()
{
	std::cout << "StaffRestRoom created\n";
	_type = RoomType::StaffRestRoom;
}

StaffRestRoom::~StaffRestRoom()
{
	std::cout << "StaffRestRoom destroyed\n";
}