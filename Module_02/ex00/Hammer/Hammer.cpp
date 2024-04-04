#include "Hammer.hpp"


Hammer::Hammer(): Tool(){
    std::cout << "Wow a beatifull Hammer (🔨)" << std::endl;
}

Hammer::~Hammer(){
    std::cout << "The Hammer is gone" << std::endl;
}

void Hammer::Use(){
    if (numberOfUses < 0)
    {
        std::cout << "The Hammer is broken" << std::endl;
        return;
    }
    std::cout << "I am a dwarf and i'm  forging something" << std::endl;
    numberOfUses--;
}
