#include "../../Header/Form.hpp"
#include "../../Header/List.hpp"
#include "../../Header/Room.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedCourseCreation)
{
	std::cout << "Enter the number of classroom needed: ";
	//std::cin >> _numberOfClassRoomNeeded;
	_numberOfClassRoomNeeded = 5;
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
	//on ajoute le nombre de classeRoom Demander dans la liste de Room
	RoomList* list = RoomList::getInstance();
		
	std::cout << "le Formulaire est bon\n";
	while(_numberOfClassRoomNeeded > 0)
	{
		std::cout << "creation en cours\n";
		Classroom *classroom = new Classroom();
		list->add(classroom);
		_numberOfClassRoomNeeded--;
	}
	
}