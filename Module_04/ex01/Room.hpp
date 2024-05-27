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
        bool canEnter(Person*);
        void enter(Person*);
        void exit(Person*);
        
        void printOccupant();
};

#endif // __ROOM_HPP__