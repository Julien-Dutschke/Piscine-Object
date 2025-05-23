
//Petite simulation pour verifier l'efficaciter des classes mises en place
//ROOM_HPP / Course.hpp / Form.hpp / Person.hpp
#include "Header/Room.hpp"
#include "Header/Course.hpp"
#include "Header/Form.hpp"
#include "Header/Person.hpp"
#include "Header/List.hpp"




class tools
{
	public:

	void static printLine()
	{
		std::cout << "----------------------------------------\n";
	}
	
	//verifie si le formulaire est du type dans le quel on veut le caster
	template<typename T, typename U>
	static bool isOfType(const T* p_form)
	{
		if (p_form == nullptr)
			return false;
		if (dynamic_cast<const U*>(p_form) != nullptr)
			return true;
		else
			return false;
	}
	
	

};

void testPerson()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Person\n";
    Person person;
    (void) person;
    tools::printLine();
}

void testRoom()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Room\n";
    Room room;
    (void) room;
    tools::printLine();
}

void testCourse()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Course\n";
    Course course("Math");
    (void) course;
    tools::printLine();
}

void testStudentList()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe Student\n";
    Student student;
    student.setName("John Doe");
    tools::printLine();

    std::cout << "test de la declaration de la classe StudentList singletons\n";
    StudentList* studentList = StudentList::getInstance();
    studentList->add(student);
    studentList->display();
    studentList->remove(student); 
    studentList->destroyInstance();
    tools::printLine();
}

void testRoomList()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe RoomList singletons\n";
    Room room;
    RoomList* roomList = RoomList::getInstance();
    roomList->add(room);
    roomList->display();
    roomList->remove(room);
    roomList->destroyInstance();
    tools::printLine();
}

void testCourseList()
{
    tools::printLine();
    std::cout << "test de la declaration de la classe CourseList singletons\n";
    Course course("Math");
    CourseList* courseList = CourseList::getInstance();
    courseList->add(course);
    courseList->display();
    courseList->remove(course);
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
    staffList->add(*secretary);
    staffList->add(*professor);
    staffList->add(*headmaster);
    staffList->display();
    staffList->remove(*secretary);
    staffList->remove(*professor);
    staffList->remove(*headmaster);
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
    Headmaster executerMaster;

    Form* formtest = secretary_factory.createForm(FormType::CourseFinished);
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

int main()
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
	clearAllLists();
    return 0;
}