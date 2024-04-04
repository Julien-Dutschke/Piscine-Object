#include "Workshop.hpp"

Workshop::Workshop()
{
    std::cout << "New Workshop constructor" << std::endl;
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
    }
}

void Workshop::executeWorkDay()
{
    std::vector<Worker*>::iterator it = workers.begin();
    while (it != workers.end())
    {
        Worker* worker = *it;
        worker->work();
        it++;
    }
}