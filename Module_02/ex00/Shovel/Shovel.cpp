#include "Shovel.hpp"

Shovel::Shovel(): Tool(){
    std::cout << "Wow a beatifull shovel (⛏️)" << std::endl;
}

Shovel::~Shovel(){
    std::cout << "The shovel is gone" << std::endl;
}

void Shovel::Use(){
    if (numberOfUses < 0)
    {
        std::cout << "The shovel is broken" << std::endl;
        return;
    }
    std::cout << "I am a dwarf and i'm digging a hole, diggy diggy hole" << std::endl;
    numberOfUses--;
}
