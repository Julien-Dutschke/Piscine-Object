#ifndef __STUDENT_HPP__
# define __STUDENT_HPP__

#include <vector>
#include "../Person.hpp"
#include "../../Cours/Cours.hpp"
#include "../../Room/Type/Classroom.hpp"

class Student : public Person
{
private:
	std::vector<Cours*> _subscribedCours;
    Classroom* _currentRoom;

public:
	bool isSubscribed(Cours* p_Cours)
    {
        for(auto it = _subscribedCours.begin(); it != _subscribedCours.end(); it++)
        {
            if(*it == p_Cours)
                return true;
        }
        return false;
    
    }
	void attendClass(Classroom* p_classroom)
    {
        std::cout << "IMPLEMENT THE ATTENDCLASS METHOD" << std::endl;
    }

	void exitClass()
    {
        if(_currentRoom != nullptr)
            _currentRoom->exit(this);
    }
	void graduate(Cours* p_Cours)
    {
        std::cout << "INPLEMENT THE GRADUATE METHOD" << std::endl;
    }
};

#endif // __STUDENT_HPP__