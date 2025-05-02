
//Petite simulation pour verifier l'efficaciter des classes mises en place
//ROOM_HPP / Course.hpp / Form.hpp / Person.hpp
#include "Header/Room.hpp"
#include "Header/Course.hpp"
#include "Header/Form.hpp"
#include "Header/Person.hpp"
#include "Header/List.hpp"

int main()
{
	//creation d'une Person
	Person person;
	(void) person;
	// Creation Room
	Room room;
	(void) room;
	// Creation Course
	Course course("Math");
	(void) course;
	// Create d'un type de Formulaire
	CourseFinishedForm courseFinishedForm;
	(void) courseFinishedForm;	

	// Test aditionnel pour verifier les Singletons 

	// creation de la StudentList
	class Student student;
	(void) student;

	student.setName("John Doe");

	StudentList* studentList = StudentList::getInstance();
	studentList->add(student);
	studentList->display();
	studentList->remove(student); 
	studentList->destroyInstance();

	// Creation de la Room List 
	RoomList* roomList = RoomList::getInstance();
	roomList->add(room);
	roomList->display();
	roomList->remove(room);
	roomList->destroyInstance();

	
	// Creation de la CourseList
	CourseList* courseList = CourseList::getInstance();
	courseList->add(course);
	courseList->display();
	courseList->remove(course);
	courseList->destroyInstance();

	//creation de StaffList 
	StaffList* staffList = StaffList::getInstance();
	
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
	
	return 0;
}




