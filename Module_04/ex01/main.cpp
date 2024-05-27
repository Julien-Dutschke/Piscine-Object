
#include "StudentList.hpp"

int main()
{
    // ! Can't instantiate cause Singletons
    // ! Need getInstance() method 
    // StudentList list("Students");
    // StaffList staff("Staff");
    // CourseList courses("Cours");
    // RoomList rooms("Rooms");

    //Fonctionne
    StudentList *list = StudentList::getInstance();
    StudentList *list2 = StudentList::getInstance();
    list->add(Student("John"));
    list2->add(Student("Wick"));
    std::cout << "------------------\n";
    list->print();
    return 0;
}



