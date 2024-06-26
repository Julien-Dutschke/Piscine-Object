#ifndef __IROOM_HPP__
#define __IROOM_HPP__

#include <iostream>
#include <vector>
#include "../Course/Course.hpp"

class Person;


class IRoom
{
    private:
    std::string _name;
    std::vector<Person*> _listOccupants;

    bool isInside(Person* p_person);

    public:
    IRoom(std::string p_name);
    virtual ~IRoom(){};
    std::string getName() const;
    std::vector<Person*> getOccupants() const;
    virtual bool addOccupant(Person* p_person);
    virtual void removeOccupant(Person* p_person);

};

class StaffRoom : public IRoom
{
    private:

    public:
    bool addOccupant(Person* p_person) override;
    StaffRoom();
    StaffRoom(std::string p_name) : IRoom(p_name){};
    StaffRoom(const StaffRoom& p_room) = delete;
    StaffRoom& operator=(const StaffRoom& p_room) = delete;
    ~StaffRoom() override{};
};

std::ostream& operator<<(std::ostream& p_ostream, const IRoom& p_room);



class Classroom : public IRoom
{
    private:
    Course* _course;

    public:
    Classroom() : IRoom("Classroom"){};

    bool setCourse(Course* p_course)
    {
        if (_course == nullptr)
            return ( _course = p_course, true);
        else
            return false;
    }
};


class SecretarialOffice: public StaffRoom
{
private:
	std::vector<Form*> _archivedForms;

public:
    SecretarialOffice() : StaffRoom("Secretarial Office"){};
    ~SecretarialOffice() override;
};



class HeadmasterOffice : public StaffRoom
{
    private:

    public:
    HeadmasterOffice() : StaffRoom("Headmaster Office"){};
};


class StaffRestRoom : public StaffRoom
{
    private:

    public:
    StaffRestRoom() : StaffRoom("Staff Rest Room"){};
};



class Courtyard : public IRoom
{
    private:

    public:
    Courtyard() : IRoom("Courtyard"){};
};
#endif