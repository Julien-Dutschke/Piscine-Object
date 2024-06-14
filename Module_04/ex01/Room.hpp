#ifndef __ROOM_HPP__
#define __ROOM_HPP__

#include <string>
#include <vector>

class Person;

class Room
{
    private:
        long long _ID;
        std::vector<Person *> _occupants;

    public:
        Room();
        long long getID(){return _ID;}
        bool canEnter(Person*);
        void enter(Person*);
        void exit(Person*);
        
        void printOccupant();
};

std::ostream& operator<<(std::ostream& os, Room& p_room)
{
    os << "Room id is :" << p_room.getID();
    return (os);
}

#endif // __ROOM_HPP__