#ifndef __CLASSROOM_HPP__
#define __CLASSROOM_HPP__

#include "Room.hpp"
#include "Course.hpp"

class Classroom : public Room
{
    private:
        Course* _currentRoom;

    public:
        Classroom();
        void assignCourse(Course* p_course);
};

#endif // __CLASSROOM_HPP__