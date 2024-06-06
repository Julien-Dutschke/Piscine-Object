

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
    Workshop(std::string name);

    // Destructeur
    ~Workshop();

    void addWorker(Worker* worker);
    void removeWorker(Worker* worker);
    bool executeWorkDay();
    

private:
    std::string _name;
    Workshop& operator=(const Workshop& workshop){ (void)workshop; return *this;}
    std::vector<Worker*> workers;
};

#endif 

