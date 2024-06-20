#ifndef __PERSON_HPP__

#include <iostream>
#include <vector>

class IRoom;

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
    IRoom* _currentRoom;
    Grade _type;

    public:
    Person(std::string p_name, Grade p_type) : _name(p_name), _type(p_type){}
    virtual ~Person(){}
    
    std::string getName() {return _name;}
    IRoom* getRoom() {return _currentRoom;}
    Grade getType() {return _type;}
    
    void setRoom(IRoom* p_room) {_currentRoom = p_room;}

    
};

std::ostream& operator<<(std::ostream& p_out, Person& p_person)
{
    p_out << "Name: " << p_person.getName() << std::endl;
    p_out << "Type: ";
    switch(p_person.getType())
    {
        case Grade::Extern:
            p_out << "Extern";
            break;
        case Grade::Student:
            p_out << "Student";
            break;
        case Grade::Staff:
            p_out << "Staff";
            break;
    }
    return p_out;
}

#endif // __PERSON_HPP__