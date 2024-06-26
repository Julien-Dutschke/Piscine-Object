#include "IRoom.hpp"
#include "../Person/Person.hpp"

IRoom::IRoom(std::string p_name) : _name(p_name){}

std::string IRoom::getName() const { return _name;}

std::vector<Person*> IRoom::getOccupants() const { return _listOccupants; }

bool  IRoom::addOccupant(Person* p_person)
{
    if (isInside(p_person) == true)
        return false;
    else
        _listOccupants.push_back(p_person);
    return true;
}

void IRoom::removeOccupant(Person* p_person)
{
    for (auto it = _listOccupants.begin(); it != _listOccupants.end(); ++it)
    {
        if (*it == p_person)
        {
            _listOccupants.erase(it);
            return;
        }
    }
}

bool IRoom::isInside(Person* p_person)
{
    for (Person* occupant : _listOccupants)
    {
        if (occupant == p_person)
            return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& p_ostream, const IRoom& p_room)
{
    p_ostream << "Room: " << p_room.getName() << "\nOccupants: \n";
    for (Person* occupant : p_room.getOccupants())
    {
        p_ostream << *occupant << std::endl;
    }
    return p_ostream;
}


StaffRoom::StaffRoom() : IRoom("Only Staff"){}


bool StaffRoom::addOccupant(Person* p_person)
{
    if (p_person->getStatus() >= e_status::STAFF)
    {
        return IRoom::addOccupant(p_person);
    }
    return false;
}