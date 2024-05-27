#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>

class Room;

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	std::string getName() {return (_name);}
	Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {}
	Room* room() {return (_currentRoom);}
};

#endif // __PERSON_HPP