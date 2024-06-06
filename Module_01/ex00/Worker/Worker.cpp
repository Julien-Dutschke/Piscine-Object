#include "Worker.hpp"

#include "../Shovel/Shovel.hpp"

void Worker::removeTool()
{
    if (tool != NULL)
    {
        tool->setWorker(NULL);
        tool = NULL;
    }
}

std::string Worker::getName()
{
    return _name;
}

Worker::Worker(){
    std::cout << "New Dwarf constructor ⚒️👷" << std::endl;
}

Worker::Worker(std::string name){
    std::cout << "New Dwarf constructor ⚒️👷" << std::endl;
    _name = name;
}

Worker::Worker(int x, int y, int level, int exp, std::string name) : position(x, y), statistic(level, exp)
{
    _name = name;
    std::cout << _name << " just arrived👷⛏️\n";
}

Worker::Worker(int x, int y, int level, int exp) : position(x, y), statistic(level, exp)
{
    std::cout << "New Dwarf constructor ⚒️👷" << std::endl;
    std::cout << "Position: " << position.x << ", " << position.y << std::endl;
}

Worker::~Worker()
{
    std::cout << "Dwarf destructor" << std::endl;
}

bool Worker::work()
{
    if (this->workshops.size() == 0)
    {
        std::cout << _name << " doesn't have any workshop" << std::endl;
        return false;
    }
    else if (this->tool == NULL)
    {
        std::cout << _name << " doesn't have any tool" << std::endl;
        return false;
    }
    else 
    {
        return (this->tool->Use());
    }
}

void Worker::addTool(Tool* tool)
{
    if (tool == NULL)
    {
        std::cout << "You know , nothing is not really a tool" << std::endl;
        return;
    }
    else if (tool->getWorker() != NULL)
    {
        Worker* worker = tool->getWorker();
        worker->removeTool();
        if (this->tool != NULL)
            this->tool->setWorker(NULL);
        this->tool = tool;
        tool->setWorker(this);
    }
    else
    {
        if (this->tool != NULL)
            this->tool->setWorker(NULL);
        this->tool = tool;
        tool->setWorker(this);
    }
    Tool* identify = dynamic_cast<Shovel*>(tool);
    if (identify != NULL)
        std::cout << "Worker " << _name << " just grab his shovel" << std::endl;
    else
        std::cout << "Worker " << _name << " just grab his hammer" << std::endl;
}

//! do not use this function it's for the workshop
void Worker::addWorkshop(Workshop* workshop)
{
    if (workshop == NULL)
    {
        std::cout << "You know , nothing is not really a workshop" << std::endl;
    }
    else if (std::find(workshops.begin(), workshops.end(), workshop) != workshops.end())
    {
        std::cout << "worker already work in this shop" << std::endl;
    }
    else
    {
        workshops.push_back(workshop);
    }
}


void Worker::removeWorkshop(Workshop* workshop)
{
    if (workshop == NULL)
    {
        std::cout << "You know , nothing is not really a workshop" << std::endl;
    }
    else if (std::find(workshops.begin(), workshops.end(), workshop) == workshops.end())
    {
        std::cout << "Worker doesn't work in this shop" << std::endl;
    }
    else
    {
        workshops.erase(std::find(workshops.begin(), workshops.end(), workshop));
    }
}