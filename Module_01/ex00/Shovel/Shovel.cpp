#include "Shovel.hpp"

Shovel::Shovel(): Tool(){
    std::cout << "Wow a beatifull shovel (⛏️)" << std::endl;
}

Shovel::~Shovel(){
    std::cout << "The shovel is gone" << std::endl;
}

bool Shovel::Use(){
    if (numberOfUses <= 0)
    {
        std::cout << "The shovel is broken" << std::endl;
        return false;
    }
    std::cout << "I am a dwarf and i'm digging a hole, diggy diggy hole" << std::endl;
    numberOfUses--;
    if (numberOfUses == 0)
    {
        std::cout << "KLINK ... whaou that a solid rock my pickaxe is broken..." << std::endl;
        return false;
    }
    return true;
}
