#include "../../Header/Form.hpp"
#include "../../Header/List.hpp"
#include "../../Header/Course.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
	std::cout << "Enter the name of the course to create: ";
	//std::cin >> _nameCourseToCreate;
	_nameCourseToCreate = "French";
}

NeedCourseCreationForm::~NeedCourseCreationForm()
{
	std::cout << "NeedCourseCreationForm destroyed\n";
}

void NeedCourseCreationForm::execute()
{
	if (isSigned() == false)
	{
		std::cout << "Form not signed\n";
		return;
	}
	std::cout << "Form is signed\n";

	std::cout << "Creating course: " << _nameCourseToCreate << std::endl;
	
	CourseList* courseList = CourseList::getInstance();
	Course *course = new Course(_nameCourseToCreate);
	courseList->add(course);
}