#include "../../Header/List.hpp"
#include "../../Header/Room.hpp"

RoomList::RoomList()
{
	std::cout << "RoomList created\n";
}

RoomList::~RoomList()
{
	std::cout << "RoomList destroyed\n";
	//on free toute les room

	std::list<Room>::iterator it;
	clear();
}

void RoomList::display() const 
{
	std::cout << "number of rooms: " << _items.size() << std::endl;
	std::list<Room>::const_iterator it;
		std::cout << "RoomList::display() called\n";
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		std::cout << "Room: " << it->getID() << std::endl;
	}	
}




