#include "StudentList.hpp"
#include "StaffList.hpp"
#include "CourseList.hpp"
#include <iostream>
#include "RoomList.hpp"

int main()
{
    // ! Can't instantiate cause Singletons
    // ! Need getInstance() method 
    // StudentList list("Students");
    // StaffList staff("Staff");
    // CourseList courses("Cours");
    // RoomList rooms("Rooms");

    // ? test StaffList
    StaffList* staff = StaffList::getInstance();
    //! shoud be same as staff
    StaffList* staff2 = StaffList::getInstance();

    if (staff == staff2)
        std::cout << "Same instance for Stafflist\n";
    else
        std::cout << "Different instance\n";

    // ? test StudentList
    StudentList* students = StudentList::getInstance();
    //! shoud be same as students
    StudentList* students2 = StudentList::getInstance();
    
    if (students == students2)
        std::cout << "Same instance for StudentList\n";
    else
        std::cout << "Different instance\n";

    // ? test CourseList
    CourseList* courses = CourseList::getInstance();
    //! shoud be same as courses
    CourseList* courses2 = CourseList::getInstance();

    if (courses == courses2)
        std::cout << "Same instance for CourseList\n";
    else
        std::cout << "Different instance\n";

    // ? test RoomList
    RoomList* rooms = RoomList::getInstance();
    //! shoud be same as rooms
    RoomList* rooms2 = RoomList::getInstance();

    if (rooms == rooms2)
        std::cout << "Same instance for RoomList\n";
    else
        std::cout << "Different instance\n";


    // ? print all addres for check different instance
    std::cout << "StaffList: " << staff << std::endl;
    std::cout << "StudentList: " << students << std::endl;
    std::cout << "CourseList: " << courses << std::endl;
    std::cout << "RoomList: " << rooms << std::endl;

    // ?destroy all instance
    staff->destroyInstance();
    students->destroyInstance();
    courses->destroyInstance();
    rooms->destroyInstance();

    //stock all instance

    return 0;
}

