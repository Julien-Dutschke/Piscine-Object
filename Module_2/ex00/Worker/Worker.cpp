#include "Worker.hpp"

void Worker::removeTool()
{
    if (tool != NULL)
    {
        tool->setWorker(NULL);
        tool = NULL;
    }
}

Worker::Worker(){
    std::cout << "New Dwarf constructor ⚒️👷" << std::endl;
}

Worker::Worker(int x, int y, int level, int exp)
{
    std::cout << "New Dwarf constructor ⚒️👷" << std::endl;
    position.x = x;
    position.y = y;
    statistic.level = level;
    statistic.exp = exp;
    std::cout << "Position: " << position.x << ", " << position.y << std::endl;
}

Worker::~Worker()
{
    std::cout << "Dwarf destructor" << std::endl;
}

void Worker::work()
{
    if (this->workshops.size() == 0)
    {
        std::cout << "Worker doesn't work in any workshop" << std::endl;
    }
    else if (this->tool == NULL)
    {
        std::cout << "Worker doesn't have a tool" << std::endl;
    }
    else
    {
        this->tool->Use();
    }
}

void Worker::addTool(Tool* tool)
{
    if (tool == NULL)
    {
        std::cout << "You know , nothing is not really a tool" << std::endl;
    }
    else if (tool->getWorker() != NULL)
    {
        Worker* worker = tool->getWorker();
        worker->removeTool();
        this->tool = tool;
        tool->setWorker(this);
    }
    else
    {
        this->tool = tool;
        tool->setWorker(this);
    }
}

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