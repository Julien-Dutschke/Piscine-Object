#ifndef ROOM_HPP
# define ROOM_HPP


#include <vector>
#include <iostream>

class Course;
class Form;
class Person;

class Room
{
	protected:
	long long _ID;
	std::vector<Person*> _occupants;

	public:
	Room() : _ID(0){ std::cout << "Room created\n"; }
	bool canEnter(Person* p){(void)p;return true;}
	void enter(Person* p){(void)p;}
	void exit(Person* p){(void)p;}

	long long getID() const {return _ID;}

	bool operator==(const Room& p_room) const
	{
		return this == &p_room;
	}

	void printOccupant()
	{
		//
		std::vector<Person*>::iterator it = _occupants.begin();
		while(it != _occupants.end())
		{
			std::cout << "Occupant :\n";
		}
		std::cout << "Need an implementation\n";
	}

};

class Classroom : public Room
{
	private:
	Course* _currentCourse;

	public:
	Classroom();
	void assignCourse(Course* p_course);
};

class SecretarialOffice: public Room
{
	private:
	std::vector<Form*> archivedForms;
};


class HeadmasterOffice : public Room
{
	private:

	public:

};


class StaffRestRoom : public Room
{
	private:

	public:
};

class Courtyard : public Room
{
	private:

	public:

};

#endif