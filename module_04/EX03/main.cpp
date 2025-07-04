
//Petite simulation pour verifier l'efficaciter des classes mises en place
//ROOM_HPP / Course.hpp / Form.hpp / Person.hpp
#include "Header/Room.hpp"
#include "Header/Course.hpp"
#include "Header/Form.hpp"
#include "Header/Person.hpp"
#include <limits>
#include "Header/List.hpp"
#include "test.hpp"

void loopGame(Headmaster* headmaster, Secretary* secretary);

void setupGame()
{
    //on creer les trois professeurs et le concierge
    Professor* prof1 = new Professor("Guliman");
    Professor* prof2 = new Professor("Leman Russ");
    Professor* prof3 = new Professor("Magnus le Rouge");
    Janitor* janitor = new Janitor("Anatoly");

    //on les ajoute a la liste du personnel
    StaffList* staffList = StaffList::getInstance();
    staffList->add(prof1);
    staffList->add(prof2);
    staffList->add(prof3);
    staffList->add(janitor);

    StudentList* studentList = StudentList::getInstance();
    //on prepare aussi 10 etudiants 
    for (int i = 0; i < 10; ++i)
    {
        Student* student = new Student(std::to_string(i + 1));
        studentList->add(student);
    }
}

void tuto()
{
    StaffList* staffList = StaffList::getInstance();
    StudentList* studentList = StudentList::getInstance();
    tools::cleanScrean();
    std::cout << "Bienvenue dans l'ecole d'aventuriers!\n";
    std::cout << "Dans cette simulation, vous allez incarner le directeur de l'ecole.\n";
    std::cout << "Vous aurez a gerer les professeurs, les eleves et les formulaires.\n";
    std::cout << "Vous pourrez interagir avec l'ecole via des formulaires.\n";

    std::cout << "Voici les differents types de formulaires que vous pourrez rencontrer:\n";
    std::cout << "1. Formulaire de fin de cours (CourseFinishedForm):\n";
    std::cout << "   - Pour signaler la fin d'un cours.\n";
    std::cout << "2. Formulaire de besoin de plus de salles (NeedMoreClassRoomForm):\n";
    std::cout << "   - Pour demander plus de salles de classe.\n";
    std::cout << "3. Formulaire de besoin de creation de cours (NeedCourseCreationForm):\n";
    std::cout << "   - Pour demander la creation d'un nouveau cours.\n";
    std::cout << "4. Formulaire d'inscription a un cours (SubscriptionToCourseForm):\n";
    std::cout << "   - Pour inscrire un eleve a un cours.\n";

    std::cout << "Il s'agit d'une simulation, vous ne pourrez pas faire grand chose pour l'instant.\n";
    std::cout << "donc moi votre secretaire, je vais vous aider a gerer l'ecole.\n";
    std::cout << "je me suis charger de recruter trois professeurs,  et un concierge c'est mon cousin et il avait besoin d'un travail.\n";
    std::cout << "Vous pouvez les voir dans la liste du personnel.\n";
    setupGame();
    std::cout << "Liste du personnel:\n\n";
    staffList->display();
    std::cout << "\nListe des etudiants:\n";
    studentList->display();
    tools::pressForContinue();

}

void start_simulation()
{
    Secretary* secretary = new Secretary("Nochance");
    Headmaster* headmaster = new Headmaster("Evaluateur");
    StaffList* staffList = StaffList::getInstance();
    staffList->add(secretary);
    staffList->add(headmaster);
    tools::cleanScrean();

    std::cout << "Bienvenue dans l'ecole d'aventuriers!\n";
    std::cout << "Bonjour Monsieur le directeur!\n";
    std::cout << "Je suis " + secretary->getName() + ", je vais vous aider a gerer l'ecole!\n";
    std::cout << "(Afficher l'introduction explicative ?) Y/N\n";
    
    // on met aussi une securite pour eviter les controle C et D 
    while(1)
    {
        std::string choice;
        std::cin >> choice;
        if (std::cin.eof() || std::cin.fail())
            return; // Sortie propre du programme
        else if (choice == "Y" || choice == "y")
        {
            tools::cleanScrean();
            tuto();
            loopGame(headmaster, secretary);
            break;
        }
        else if (choice == "N" || choice == "n")
        {
            tools::cleanScrean();
            setupGame();
            loopGame(headmaster, secretary);
            break;
        }
        else
        {
            std::cout << "Choix invalide, veuillez entrer Y ou N.\n";
        }
    }
}

//fonction qui recupere le int dans le terminal
int getIntFromTerminal(int max)
{
    int value;
    while (true)
    {
        std::cin >> value;

        if (std::cin.fail() || std::cin.eof())
        {
            std::cout << "Sortie de  la Simulation.\n(bad ending: you comitted seppuku)\n";
            exit(0);
        }
        else if (value > max || value < 0)
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne
            std::cout << "Entrée invalide, veuillez reessayer.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne
            std::cin.clear(); 
            return value;
        }
    }
}

void printMenu()
{
    tools::cleanScrean();
    std::cout << "Menu Principal:\n";
    std::cout << "1. Afficher la liste du personnel\n";
    std::cout << "2. Afficher la liste des etudiants\n";
    std::cout << "3. Demandez aux professeurs de faire cours\n";
    std::cout << "4. Quitter le jeu\n";
    std::cout << "Veuillez entrer votre choix: ";
}

// Boucle principale du jeu , normalement certain professeurs et le directeur ainsi que le secretaire
// sont deja dans la liste des staff
void loopGame(Headmaster* headmaster, Secretary* secretary)
{
    (void)secretary; // Pour éviter l'avertissement de variable inutilisée
    while(1)
    {
        tools::cleanScrean();
        printMenu();
        int choice = getIntFromTerminal(4);
        switch (choice)
        {
        case 1:
            tools::cleanScrean();
            StaffList::getInstance()->display();
            break;
        case 2:
            tools::cleanScrean();
            StudentList::getInstance()->display();
            break;
        case 3:
            tools::cleanScrean();
            headmaster->askProfessorsToTeach();
            break;
        case 4:
            break;
        
        default:
            break;
        }
        tools::pressForContinue();
    }

}

int main()
{
    //testUnitaires();
    start_simulation();
    clearAllLists();
    std::cout << "Simulation terminee, merci d'avoir joue!\n";
    return 0;
}

