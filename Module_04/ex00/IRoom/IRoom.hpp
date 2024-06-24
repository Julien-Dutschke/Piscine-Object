#ifndef __IROOM_HPP__
#define __IROOM_HPP__

#include <iostream>
#include <vector>

class Person;

class IRoom
{
    private:
    std::string _name;
    std::vector<Person*> _listOccupants;

    bool isInside(Person* p_person);

    public:
    IRoom(std::string p_name);
    std::string getName() const;
    std::vector<Person*> getOccupants() const;
    void addOccupant(Person* p_person);
    void removeOccupant(Person* p_person);

};

std::ostream& operator<<(std::ostream& p_ostream, const IRoom& p_room);

#endif