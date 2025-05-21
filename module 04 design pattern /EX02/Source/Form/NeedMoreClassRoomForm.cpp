#include "../../Header/Form.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedCourseCreation)
{
}

NeedMoreClassRoomForm::~NeedMoreClassRoomForm()
{
	std::cout << "NeedMoreClassRoomForm destroyed\n";
}


void NeedMoreClassRoomForm::execute()
{
	if (isSigned() == false)
	{
		std::cout << "Form not signed\n";
		return;
	}
	std::cout << "NeedMoreClassRoomForm\n";
}