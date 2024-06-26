//? Test de la restructuration du datas.hpp
#include <iostream>
#include <vector>

#include "IRoom/IRoom.hpp"
#include "Person/Person.hpp"


int main()
{
    IRoom room("Courtyard");
    IRoom staffRoom("Staff Room");

    Person student("John", e_status::STUDENT);
    Person staff("Jane", e_status::STAFF);

    student.enterRoom(&room);
    std::cout << "Localisation: " << room << std::endl;
    std::cout << student << std::endl;

    staff.enterRoom(&staffRoom);
    std::cout << "Localisation: " << staffRoom << std::endl;
    std::cout << staff << std::endl;
    return 0;
}
