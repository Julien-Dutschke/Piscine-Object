#include "../../Header/Room.hpp"

long long Room::_IDCounter = 0;

Room::Room() : _ID(_IDCounter), _type(RoomType::ClassRoom)
{
	_IDCounter++;
}

Room::~Room()
{
}

bool Room::canEnter(Person* p_person)
{
	(void)p_person;
	return true;
}

void Room::enter(Person* p_person)
{
	if (canEnter(p_person))
	{
		_occupants.push_back(p_person);
		std::cout << "Person entered the room\n";
	}
	else
	{
		std::cout << "Person cannot enter the room\n";
	}
}

//ToDo: implement the exit function
void Room::exit(Person* p_person)
{
	(void)p_person;
}

long long Room::getID() const
{
	return _ID;
}

bool Room::operator==(const Room& p_room) const
{
	return this == &p_room;
}

void Room::printOccupant()
{
	std::vector<Person*>::iterator it = _occupants.begin();
	while(it != _occupants.end())
	{
		std::cout << "Occupant :\n";
	}
	std::cout << "Need an implementation\n";
}

RoomType Room::getType() const
{
	return _type;	
}