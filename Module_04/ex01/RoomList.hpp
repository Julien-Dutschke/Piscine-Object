#ifndef __ROOMLIST_HPP__
#define __ROOMLIST_HPP__

#include "AList.hpp"

#include "Room.hpp"

class RoomList : public AList<Room, RoomList>
{
    private:
    RoomList() : AList<Room, RoomList>("Room List") {}
    RoomList(std::string name) : AList<Room, RoomList>(name) {}
    
    public:
     std::string getName() const { return _name; }
};

#endif