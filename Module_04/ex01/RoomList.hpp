#ifndef __ROOMLIST_HPP__
#define __ROOMLIST_HPP__

#include "Singletons.hpp"
#include "Room.hpp"
#include <list>
#include "ListPrinter.hpp"



class RoomList : public std::list<Room*>, public Singletons<RoomList>, public ListPrinter
{
    private:
    friend class Singletons<RoomList>;

    private:
        RoomList(){}
        RoomList(std::string name) = delete;
        RoomList(const RoomList& other) = delete;

    public:

};

#endif