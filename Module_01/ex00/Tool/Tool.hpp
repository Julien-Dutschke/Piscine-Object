

#ifndef __TOOL_HPP__
#define __TOOL_HPP__


#include <iostream>

class Shovel;
class Hammer;
class Worker;


class Tool {
public:
    // Constructeurs
    Tool();

    // Destructeur
    virtual ~Tool();

    // Méthodes
    virtual bool Use() = 0;
    Worker* getWorker(){ return worker;}
    void setWorker(Worker* worker){ this->worker = worker;}

    protected:
    unsigned int numberOfUses;
    Worker* worker;

};

#endif 