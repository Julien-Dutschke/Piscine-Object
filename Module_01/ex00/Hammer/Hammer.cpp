#include "Hammer.hpp"


Hammer::Hammer(): Tool(){
    std::cout << "Wow a beatifull Hammer (🔨)" << std::endl;
}

Hammer::~Hammer(){
    std::cout << "The Hammer is gone" << std::endl;
}

bool Hammer::Use(){
    if (numberOfUses <= 0)
    {
        std::cout << "The Hammer is broken" << std::endl;
        return false;
    }
    std::cout << "I am a dwarf and i'm  forging something" << std::endl;
    numberOfUses--;
    if (numberOfUses == 0)
    {
        std::cout << " KLONKK my hammer is broke , i need another hammer for my job here" << std::endl;
        return false;
    }
    return true;
}

