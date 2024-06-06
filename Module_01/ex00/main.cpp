#include "Tool/Tool.hpp"
#include "Hammer/Hammer.hpp"
#include "Shovel/Shovel.hpp"
#include "Worker/Worker.hpp"
#include "Workshop/Workshop.hpp"



int main()
{
    std::vector<Worker*> NainsMoria;
    std::vector<Worker*> NainsErebor;
    Workshop* Moria = new Workshop(" The Moria Mines");
    Workshop* Erebor = new Workshop("The Great Forges of Erebor");
    

    // Création des outils
    std::vector<Tool*> Tools;
    for(int i = 0; i < 7; i++)
        Tools.push_back(new Hammer());
    for(int i = 0; i < 7; i++)
        Tools.push_back(new Shovel());

    // Nain Moria <shovel> "Pioche"
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Gimli"));
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Balin"));
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Dwalin"));
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Train"));
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Ori"));
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Nori"));
    NainsMoria.push_back(new Worker(0, 0, 1, 0, "Dori"));

    // Nain Erebor <Marteau>
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Thorin"));
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Fili"));
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Kili"));
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Gloin"));
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Bifur"));
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Bofur"));
    NainsErebor.push_back(new Worker(0, 0, 1, 0, "Bombur"));

    // Ajout des outils
    for(int i = 0; i < 7; i++)
        NainsMoria[i]->addTool(Tools[i + 7]);
    for(int i = 0; i < 7; i++)
        NainsErebor[i]->addTool(Tools[i]);

    // Ajout des ateliers
    for(int i = 0; i < 7; i++)
    {
        Moria->addWorker(NainsMoria[i]);
        Erebor->addWorker(NainsErebor[i]);
    }

    // Travail des nains

    while(42)
    {
        if (Moria->executeWorkDay() == false)
            break;
        if (Erebor->executeWorkDay() == false)
            break;
    }

    // test de getTool
    Tool* test = NainsMoria[0]->getTool<Hammer>();
    if (test != NULL)
        std::cout << "Echec" << std::endl;
    else
        std::cout << "Reussite" << std::endl;

}
