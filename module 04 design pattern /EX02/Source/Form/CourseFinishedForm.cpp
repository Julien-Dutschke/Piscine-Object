#include "../../Header/Form.hpp"
#include "../../Header/Course.hpp"
#include "../../Header/List.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
		std::cout << "Enter the name of the course to finish: ";
		//std::cin >> _nameCourseToFinished;
		_nameCourseToFinished = "Math";
		std::cout << "the course to finish is : " << _nameCourseToFinished << std::endl;
}

CourseFinishedForm::~CourseFinishedForm()
{
	std::cout << "CourseFinishedForm destroyed\n";
}


//TODO : faire un formulaire de fin de cours
void CourseFinishedForm::execute()
{
	if (isSigned() == false)
	{
		std::cout << "Form not signed\n";
		return;
	}
	std::cout << "CourseFinishedForm activate\n";

	
	CourseList* courseList = CourseList::getInstance();
	Course* course = courseList->getCourse(_nameCourseToFinished);

	if (course == nullptr)
	{
		std::cout << "Course not found\n";
		return;
	}
	else
	{
		std::cout << "Course found\n";
		course->stop();
		courseList->remove(*course);
		std::cout << "Course " << _nameCourseToFinished << " finished\n";
	}

}