#include "../../Header/Form.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
	std::cout << "Enter the name of the course to create: ";
	//std::cin >> _nameCourseToCreate;
	_nameCourseToCreate = "French";
	std::cout << "the course to create is : " << _nameCourseToCreate << std::endl;
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
	std::cout << "NeedCourseCreationForm\n";
}