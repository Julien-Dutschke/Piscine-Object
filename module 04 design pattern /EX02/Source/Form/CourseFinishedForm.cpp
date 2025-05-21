#include "../../Header/Form.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
		std::cout << "Enter the name of the course to finish: ";
		std::cin >> _nameCourseToFinished;
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
}