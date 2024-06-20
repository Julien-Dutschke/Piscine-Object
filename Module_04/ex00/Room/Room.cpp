#include "Room.hpp"


IRoom::IRoom(long long p_ID, Grade p_type) : IRoom(p_ID, p_type){}

bool IRoom::canEnter(Person* p_person)
{
    if (p_person->getType() >= _type)
    {
        return true;
    }
    return false;
}

void IRoom::enter(Person* p_person)
{
    if (canEnter(p_person))
    {
        p_person->getRoom()->exit(p_person);
        _occupants.push_back(p_person);
        p_person->setRoom(this);
    }
}

void IRoom::exit(Person* p_person)
{
    if (find(p_person) != nullptr)
    {
        for(auto it = _occupants.begin(), ite = _occupants.end(); it != ite; it++)
            {
                if((*it) == p_person)
				{
					_occupants.erase(it);
					p_person->setRoom(nullptr);
					return;
				}
            }
    }
}

Person* IRoom::find(Person* p_person)
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

void IRoom::printOccupant()
{
    std::cout << "Occupants of the room " << _ID << " are: " << std::endl;
    for(auto it = _occupants.begin(), ite = _occupants.end(); it != ite; ++it)
    {
        std::cout << (*it)->getName() << std::endl;
    }
}

bool IRoom::isInRoom(Person* p_person)
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