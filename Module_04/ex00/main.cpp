//? Test de la restructuration du datas.hpp
#include <iostream>
#include <vector>

#include "IRoom/IRoom.hpp"
#include "Person/Person.hpp"


int main()
{
    IRoom room("Courtyard");

    Person student("John", e_status::STUDENT);
    std::cout << "Localisation: " << room << std::endl;
    std::cout << student << std::endl;
    return 0;
}