#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>
#include <vector>

#include "../Status/Status.hpp"

class IRoom;

class Person
{
    private:
    std::string _name;
    e_status _status;
    IRoom* _currentRoom = nullptr;


    public:
    Person(std::string p_name, e_status p_status);
    void enterRoom(IRoom* p_room);
    std::string getName() const;
    e_status getStatus() const;
    IRoom* getRoom();
};

class Student : public Person
{
    private:
    // ! std::vector<Course*> _subscribedCourse;
    public:
    //void attendClass(Classroom* p_classroom);
	//void exitClass();
	//void graduate(Course* p_course);
    Student(std::string p_name) : Person(p_name, e_status::STUDENT){}
};

std::ostream& operator<<(std::ostream& p_ostream, const Person& p_person);

#endif