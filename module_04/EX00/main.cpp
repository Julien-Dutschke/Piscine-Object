
//Petite simulation pour verifier l'efficaciter des classes mises en place
//ROOM_HPP / Course.hpp / Form.hpp / Person.hpp
#include "Header/Room.hpp"
#include "Header/Course.hpp"
#include "Header/Form.hpp"
#include "Header/Person.hpp"

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

	
	return 0;
}
