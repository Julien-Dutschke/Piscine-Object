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
	static long long _IDCounter;
	std::string _type;

	std::vector<Person*> _occupants;

	public:
	Room();
	~Room();

	std::string getType() const;
	bool canEnter(Person* p);
	void enter(Person* p);
	void exit(Person* p);
	long long getID() const;
	bool operator==(const Room& p_room) const;
	void printOccupant();

};


class Classroom : public Room
{
	private:
	Course* _currentCourse;

	public:
	Classroom();
	~Classroom();
	void assignCourse(Course* p_course);
};

class SecretarialOffice: public Room
{
	private:
	std::vector<Form*> archivedForms;

	public:
	SecretarialOffice();
	~SecretarialOffice();
};


class HeadmasterOffice : public Room
{
	private:

	public:
	HeadmasterOffice();
	~HeadmasterOffice();
};


class StaffRestRoom : public Room
{
	private:

	public:
	StaffRestRoom();
	~StaffRestRoom();
};

class Courtyard : public Room
{
	private:

	public:
	Courtyard();
	~Courtyard();

};

#endif