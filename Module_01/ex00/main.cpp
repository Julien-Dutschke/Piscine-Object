#include "Tool/Tool.hpp"
#include "Hammer/Hammer.hpp"
#include "Shovel/Shovel.hpp"
#include "Worker/Worker.hpp"
#include "Workshop/Workshop.hpp"

int main()
{
    Workshop* workshop = new Workshop();

    for (int i = 0; i < 10; i++)
    {
        Worker* worker = new Worker(i, i, i, i);
        Tool* tool = new Shovel();
        worker->addTool(tool);
        workshop->addWorker(worker);
    }

    for (int i = 0; i < 10; i++)
    {
        Worker* worker = new Worker(i, i, i, i);
        Tool* tool = new Hammer();
        worker->addTool(tool);
        workshop->addWorker(worker);
    }
    Worker* feneant = new Worker();
    workshop->addWorker(feneant);
     
    workshop->executeWorkDay();

    delete workshop;

    return 0;
}