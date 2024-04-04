

#ifndef __WORKSHOP_HPP__
#define __WORKSHOP_HPP__

#include <iostream>
#include "../Worker/Worker.hpp"
#include <vector>
#include <algorithm>

class Workshop {
public:
    // Constructeurs
    Workshop();

    // Destructeur
    ~Workshop();

    void addWorker(Worker* worker);
    void executeWorkDay();
    

private: 
    std::vector<Worker*> workers;
};

#endif 