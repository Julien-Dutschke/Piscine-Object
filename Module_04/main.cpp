
//Petite simulation pour verifier l'efficaciter des classes mises en place
//ROOM_HPP / Course.hpp / Form.hpp / Person.hpp
#include "Header/Room.hpp"
#include "Header/Course.hpp"
#include "Header/Form.hpp"
#include "Header/Person.hpp"

int main()
{
	// Create a new Room
	Room room;
	(void) room;
	Person person;
	(void) person;
	// Create a new Course
	Course course("Math");
	(void) course;
	// Create a new Form
	CourseFinishedForm courseFinishedForm;
	(void) courseFinishedForm;
	


	return 0;
}
