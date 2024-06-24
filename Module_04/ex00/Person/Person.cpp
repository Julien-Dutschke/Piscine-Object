#include "Person.hpp"
#include "../IRoom/IRoom.hpp"

Person::Person(std::string p_name, e_status p_status) : _name(p_name), _status(p_status){}

void Person::enterRoom(IRoom* p_room)
{
    if (_currentRoom == nullptr)
    {
        _currentRoom = p_room;
        p_room->addOccupant(this);
    }
    else
    {
        _currentRoom->removeOccupant(this);
        _currentRoom = p_room;
        p_room->addOccupant(this);
    }
        
}

std::string Person::getName() const { return _name; }

e_status Person::getStatus() const { return _status; }

IRoom* Person::getRoom() { return _currentRoom; }

std::ostream& operator<<(std::ostream& p_ostream, const Person& p_person)
{
    p_ostream << "Name: " << p_person.getName() << " Status: " << static_cast<int>(p_person.getStatus());
    return p_ostream;
}

