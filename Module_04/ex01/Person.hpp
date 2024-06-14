#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>
#include <iostream>
#include "Room.hpp"

class Room;

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Room* getRoom() {return (_currentRoom);}
	std::string getName() {return (_name);}
	Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {}
	Room* room() {return (_currentRoom);}
};


std::ostream& operator<<(std::ostream& os, Person& p_person)
{
	os << p_person.getName();
	return (os);
}


#endif // __PERSON_HPP