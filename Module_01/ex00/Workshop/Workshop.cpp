#include "Workshop.hpp"

Workshop::Workshop()
{
    std::cout << "New Workshop constructor" << std::endl;
    _name = "Workshop";
}

Workshop::Workshop(std::string name) : _name(name)
{
    std::cout << "Welcome to the " << _name << std::endl;
}


Workshop::~Workshop(){
}

void Workshop::addWorker(Worker* worker)
{
    if (worker == NULL)
    {
        std::cout << "You know , nothing is not really a worker" << std::endl;
    }
    else if (std::find(workers.begin(), workers.end(), worker) != workers.end())
    {
        std::cout << "Worker already in the workshop" << std::endl;
    }
    else
    {
        workers.push_back(worker);
        worker->addWorkshop(this);
        std::cout << "Worker " << worker->getName() << " just joined "<< _name  << std::endl;
    }
}

bool Workshop::executeWorkDay()
{
    int fired = 0;
    if (workers.size() == 0)
    {
        std::cout << "No workers in the workshop" << std::endl;
        return (false);
    }

    std::vector<Worker*>::iterator it = workers.begin();
    while (it != workers.end())
    {
        Worker* worker = *it;
        if (worker->work() == false)
        {
            std::cout << worker->getName() << " is fired" << std::endl;
            it = workers.erase(it);
            fired++;
        }
        else
            it++;
    }



    if (fired != 0)
        return (false);
    return (true);
}

void Workshop::removeWorker(Worker* worker)
{
    if (worker == NULL)
    {
        std::cout << "You know , nothing is not really a worker" << std::endl;
    }
    else if (std::find(workers.begin(), workers.end(), worker) == workers.end())
    {
        std::cout << "Worker doesn't work in the workshop" << std::endl;
    }
    else
    {
        workers.erase(std::remove(workers.begin(), workers.end(), worker), workers.end());
        worker->removeWorkshop(this);
    }
}