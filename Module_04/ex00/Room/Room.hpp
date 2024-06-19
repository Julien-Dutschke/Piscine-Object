#ifndef __ROOM_HPP__


#include <iostream>
#include "../Person/Person.hpp"
#include <memory>

class IRoom
{
    protected:
    Grade _type;
    long long _ID;
    std::vector<Person*> _occupants;


    public:
    IRoom(long long p_ID, Grade p_type);
    virtual ~IRoom(){}

    long long getID() {return _ID;}
    std::vector<Person*> getOccupants() {return _occupants;}

    void setID(long long p_ID) {_ID = p_ID;}

    virtual bool canEnter(Person* p_person);
    virtual void enter(Person* p_person);
    virtual void exit(Person* p_person);
    virtual void printOccupant();
    virtual Person* find(Person* p_person);
    
    virtual bool isInRoom(Person* p_person);
    

};


#endif // __ROOM_HPP__