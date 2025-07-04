#include "../../Header/List.hpp"
#include "../../Header/Room.hpp"

RoomList::RoomList()
{
}

RoomList::~RoomList()
{
    for (auto it = _items.begin(); it != _items.end(); )
	{
        delete *it;
        it = _items.erase(it);
    }
}

void RoomList::display() const 
{
	std::cout << "number of rooms: " << _items.size() << std::endl;
	std::cout << "RoomList::display() called\n";
	for (Room *room : _items)
	{
		std::cout << "Room: " << room->getID() << std::endl;
	}	
}




