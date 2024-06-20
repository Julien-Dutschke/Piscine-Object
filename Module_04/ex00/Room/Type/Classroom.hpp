#ifndef __CLASSROOM_HPP__
#define __CLASSROOM_HPP__

#include <iostream>
#include "../../Cours/Cours.hpp"
#include "../Room.hpp"

class Classroom : public IRoom
{
    private:
    Cours* _currentInstance;

    public:
    Classroom(long long p_ID) : IRoom(p_ID, Grade::Student), _currentInstance(nullptr){}
    void setCurrentInstance(Cours* p_instance) {_currentInstance = p_instance;}
    virtual ~Classroom(){}
};

#endif // __CLASSROOM_HPP__