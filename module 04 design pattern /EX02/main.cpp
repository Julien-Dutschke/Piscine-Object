
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

int main()
{
	tools::printLine();
	//creation d'une Person
	std::cout << "test de la declaration de la classe Person\n";
	Person person;
	(void) person;
	tools::printLine();

	// Creation Room
	std::cout << "test de la declaration de la classe Room\n";
	Room room;
	(void) room;
	tools::printLine();


	// Creation Course
	std::cout << "test de la declaration de la classe Course\n";
	Course course("Math");
	(void) course;
	tools::printLine();
	
	// !Create d'un type de Formulaire
	std::cout << "Le test de declaration de la classe Form est desactiver a cause de la nouvelle factory\n";
	tools::printLine();
	//CourseFinishedForm courseFinishedForm;
	//(void) courseFinishedForm;	
	// ! DEPRECATED 

	//* Test aditionnel pour verifier les Singletons 

	// creation de la StudentList
	std::cout << "test de la declaration de la classe Student\n";
	class Student student;
	(void) student;
	student.setName("John Doe");
	tools::printLine();

	// Creation de la Student List
	std::cout << "test de la declaration de la classe StudentList singletons\n";
	StudentList* studentList = StudentList::getInstance();
	studentList->add(student);
	studentList->display();
	studentList->remove(student); 
	studentList->destroyInstance();
	tools::printLine();


	// Creation de la Room List
	std::cout << "test de la declaration de la classe RoomList singletons\n";
	RoomList* roomList = RoomList::getInstance();
	roomList->add(room);
	roomList->display();
	roomList->remove(room);
	roomList->destroyInstance();
	tools::printLine();

	
	// Creation de la CourseList
	std::cout << "test de la declaration de la classe CourseList singletons\n";
	CourseList* courseList = CourseList::getInstance();
	courseList->add(course);
	courseList->display();
	courseList->remove(course);
	courseList->destroyInstance();
	tools::printLine();

	//creation de StaffList 
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

	//* test pour verifier la classe Secretary qui est une factory
	Secretary secretary_factory;
	Headmaster executerMaster;

	Form* formCourseFinish = secretary_factory.createForm(FormType::NeedCourseCreation);
	std::cout << "les test suivants sont pour verifier le bon fonctionnement de la factory\n";
	std::cout << "0 si c'est pas le bon type et 1 si c'est le bon type\n";
	std::cout << "le formulaire [CourseFinished] : " << tools::isOfType<Form, CourseFinishedForm>(formCourseFinish) << std::endl;
	std::cout << "le formulaire [NeedMoreClassRoom] : " << tools::isOfType<Form, NeedMoreClassRoomForm>(formCourseFinish) << std::endl;
	std::cout << "le formulaire [NeedCourseCreation] : " << tools::isOfType<Form, NeedCourseCreationForm>(formCourseFinish) << std::endl;
	std::cout << "le formulaire [SubscriptionToCourseForm] : " << tools::isOfType<Form, SubscriptionToCourseForm>(formCourseFinish) << std::endl;

	executerMaster.signForm(formCourseFinish);
	formCourseFinish->execute();
	
	return 0;
}




