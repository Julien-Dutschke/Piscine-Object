#include "Room.hpp"


Room::Room(long long p_ID, RoomType p_type) : IRoom(p_ID, p_type){}

bool Room::canEnter(Person* p_person)
{
    if (p_person->getType() >= _type)
    {
        return true;
    }
    return false;
}

void Room::enter(Person* p_person)
{
    if (canEnter(p_person))
    {
        p_person->getRoom()->exit(p_person);
        _occupants.push_back(p_person);
        p_person->setRoom(this);
    }
}

void Room::exit(Person* p_person)
{
    if (find(p_person) != nullptr)
    {
        _occupants.erase(std::remove(_occupants.begin(), _occupants.end(), p_person), _occupants.end());
        p_person->setRoom(nullptr);
    }
}

Person* Room::find(Person* p_person)
{
    for(auto it = _occupants.begin(), ite = _occupants.end(); it != ite; ++it)
    {
        if((*it) == p_person)
        {
            return (*it);
        }
    }
    return nullptr;
}

void Room::printOccupant()
{
    std::cout << "Occupants of the room " << _ID << " are: " << std::endl;
    for(auto it = _occupants.begin(), ite = _occupants.end(); it != ite; ++it)
    {
        std::cout << (*it)->getName() << std::endl;
    }
}

virtual bool Room::isInRoom(Person* p_person)
{
    for(auto it = _occupants.begin(), ite = _occupants.end(); it != ite; it++)
    {
        if((*it) == p_person)
        {
            return true;
        }
    }
    return false;
}