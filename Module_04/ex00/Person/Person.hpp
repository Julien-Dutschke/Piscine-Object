#ifndef __PERSON_HPP__

#include <iostream>
#include <vector>

class Room;

enum class Grade
{
    Extern,
    Student,
    Staff
};


class Person
{
    protected:
    std::string _name;
    Room* _currentRoom;
    Grade _type;

    public:
    Person(std::string p_name, Grade p_type) : _name(p_name), _type(p_type){}
    virtual ~Person(){}
    
    std::string getName() {return _name;}
    Room* getRoom() {return _currentRoom;}
    Grade getType() {return _type;}
    
    void setRoom(Room* p_room) {_currentRoom = p_room;}

    
};

#endif // __PERSON_HPP__