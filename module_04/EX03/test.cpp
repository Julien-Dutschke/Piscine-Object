
//Petite simulation pour verifier l'efficaciter des classes mises en place
//ROOM_HPP / Course.hpp / Form.hpp / Person.hpp
#include "Header/Room.hpp"
#include "Header/Course.hpp"
#include "Header/Form.hpp"
#include "Header/Person.hpp"
#include <limits>
#include "Header/List.hpp"

#include "test.hpp"

void testPerson()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Person\n";
    Person person("Test Person");
    std::cout << "Name: " << person.getName() << std::endl;
    if (person.getName() == "Test Person")
    {
        std::cout << "\033[1m\033[32mPerson class works correctly.\033[0m\n";
    }
    else
    {
        std::cout << "\033[1m\033[31mPerson class does not work correctly.\033[0m\n";
    }
}

void testRoom()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Room\n";

    Room room; // Exemple de nom de salle
    std::cout << "Room name: " << room.getID() << std::endl;

    if (room.getID() == 0)
    {
        std::cout << "\033[1m\033[32mRoom class works correctly.\033[0m\n";
    }
    else
    {
        std::cout << "\033[1m\033[31mRoom class does not work correctly.\033[0m\n";
    }

}

void testCourse()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Course\n";

    Course course("Apprentissage de la destruction de masse");
    std::cout << "Course title: " << course.getName() << std::endl;

    if (course.getName() == "Apprentissage de la destruction de masse")
    {
        std::cout << "\033[1m\033[32mCourse class works correctly.\033[0m\n";
    }
    else
    {
        std::cout << "\033[1m\033[31mCourse class does not work correctly.\033[0m\n";
    }
}

void testStudentList()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Student\n";
    Student *student = new Student("Finn l'humain");

    std::cout << "\ntest de la declaration de la classe StudentList singletons\n";
    
    StudentList* studentList = StudentList::getInstance();
    studentList->add(student);
    studentList->display();
    studentList->remove(student); 
    delete student;
    studentList->destroyInstance();
}

void testRoomList()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe RoomList singletons\n";
    Room *room = new Room();
    RoomList* roomList = RoomList::getInstance();
    roomList->add(room);
    roomList->display();
    roomList->remove(room);
    delete(room);
    roomList->destroyInstance();
}

void testCourseList()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe CourseList singletons\n";
    Course *course = new Course("Math");
    CourseList* courseList = CourseList::getInstance();
    courseList->add(course);
    courseList->display();
    courseList->remove(course);
    delete course;
    courseList->destroyInstance();
    tools::printLine();
}

void testStaffList()
{
    tools::printLine();
    StaffList* staffList = StaffList::getInstance();
    std::cout << "test de la declaration de la classe CourseList singletons\n";
    Staff* secretary = new Secretary();
    Staff* professor = new Professor();
    Staff* headmaster = new Headmaster();

    staffList->add(secretary);
    staffList->add(professor);
    staffList->add(headmaster);
    staffList->display();
    staffList->remove(secretary);
    staffList->remove(professor);
    staffList->remove(headmaster);
    staffList->destroyInstance();
    delete secretary;
    delete professor;
    delete headmaster;
    tools::printLine();
}

void testSecretaryFactory()
{
    tools::printLine();
    Secretary secretary_factory;

    Form* formtest = secretary_factory.createForm(FormType::NeedMoreClassRoom);
    std::cout << "les test suivants sont pour verifier le bon fonctionnement de la factory\n";
    std::cout << "0 si c'est pas le bon type et 1 si c'est le bon type\n";
    std::cout << "le formulaire [CourseFinished] : " << tools::isOfType<Form, CourseFinishedForm>(formtest) << std::endl;
    std::cout << "le formulaire [NeedMoreClassRoom] : " << tools::isOfType<Form, NeedMoreClassRoomForm>(formtest) << std::endl;
    std::cout << "le formulaire [NeedCourseCreation] : " << tools::isOfType<Form, NeedCourseCreationForm>(formtest) << std::endl;
    std::cout << "le formulaire [SubscriptionToCourseForm] : " << tools::isOfType<Form, SubscriptionToCourseForm>(formtest) << std::endl;
    delete formtest;
    tools::printLine();
}

void testFormsExecution()
{
    tools::printLine();
    Secretary secretary_factory;
    Headmaster executerMaster;

    std::cout << "le formulaire [CourseFinished] \n";
    Form* formCourseFinish = secretary_factory.createForm(FormType::CourseFinished);
    executerMaster.signForm(formCourseFinish);
    formCourseFinish->execute();
    delete formCourseFinish;
    tools::printLine();

    std::cout << "le formulaire [NeedMoreClassRoom] \n";
    Form* formNeedMoreClassRoom = secretary_factory.createForm(FormType::NeedMoreClassRoom);
    executerMaster.signForm(formNeedMoreClassRoom);
    formNeedMoreClassRoom->execute();
    delete formNeedMoreClassRoom;
    tools::printLine();

    std::cout << "le formulaire [NeedCourseCreation] \n";
    Form* formNeedCourseCreation = secretary_factory.createForm(FormType::NeedCourseCreation);
    executerMaster.signForm(formNeedCourseCreation);
    formNeedCourseCreation->execute();
    delete formNeedCourseCreation;
    tools::printLine();

    std::cout << "le formulaire [SubscriptionToCourse] \n";
    Form* formSubscriptionToCourse = secretary_factory.createForm(FormType::SubscriptionToCourse);
    executerMaster.signForm(formSubscriptionToCourse);
    formSubscriptionToCourse->execute();
    delete formSubscriptionToCourse;
    tools::printLine();
}

//! les instances de listes sont des singletons mais chaque instance est une allocation dynamique
//! donc il faut les liberer a la fin du programme si une instance a ete call aumoins une fois
//! sinon le destructeur de la classe singleton ne sera pas appele
void clearAllLists()
{
	StudentList::getInstance()->destroyInstance();
	RoomList::getInstance()->destroyInstance();
	CourseList::getInstance()->destroyInstance();
	StaffList::getInstance()->destroyInstance();
}

void testPrintAllTypes()
{
    std::cout << "Test d'affichage de type\n" << std::endl;
    StaffList* staffList = StaffList::getInstance();
    Professor* prof1 = new Professor("Prof1");
    Professor* prof2 = new Professor("Prof2");
    Professor* prof3 = new Professor("Prof3");
    staffList->add(prof1);
    staffList->add(prof3);
    Headmaster* headmaster = new Headmaster("nochance");
    Secretary* secretary = new Secretary("monika");
    staffList->add(headmaster);
    staffList->add(secretary);
    staffList->add(prof2);
    Janitor* anatoly = new Janitor("anatoly");

    staffList->add(anatoly);
    //on essais de les caster en professeur mais depuis la liste 
    for (auto staff : staffList->getItems())
    {
        if (auto professor = dynamic_cast<Professor*>(staff))
        {
            std::cout << "Found a Professor: " << professor->getName() << std::endl;
        }
        else if (auto headmaster = dynamic_cast<Headmaster*>(staff))
        {
            std::cout << "Found a Headmaster: " << headmaster->getName() << std::endl;
        }
        else if (auto secretary = dynamic_cast<Secretary*>(staff))
        {
            std::cout << "Found a Secretary: " << secretary->getName() << std::endl;
        }
        else if (Janitor *janitor = dynamic_cast<Janitor*>(staff))
        {
            std::cout << "Found a Janitor: " << janitor->getName() << std::endl;
            janitor->cleanHere();
        }
        else
        {
            std::cout << "Found an unknown staff type." << std::endl;
        }
    }


}


void testUnitaires()
{
    testPerson();
    testRoom();
    testCourse();
    testStudentList();
    testRoomList();
    testCourseList();
    testStaffList();
    testSecretaryFactory();
    testFormsExecution();
    testPrintAllTypes();
	clearAllLists();
}