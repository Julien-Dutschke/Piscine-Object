#include "../../Header/Person.hpp"
#include "../../Header/Form.hpp"
#include "../../Header/List.hpp"

Headmaster::Headmaster() : Staff("Headmaster")
{
}

Headmaster::Headmaster(std::string name) : Staff("Headmaster " + name)
{
}

Headmaster::~Headmaster()
{
}

bool Headmaster::validateForm(Form* p_form)
{
	if (p_form == nullptr)
		return false;
	if (p_form->isSigned())
	{
		p_form->execute();
		return true;
	}
	else
	{
		std::cout << "Form not signed\n";
		return false;
	}
}

bool Headmaster::signForm(Form* p_form)
{
	if (p_form == nullptr)
		return false;
	else
	{
		sign(p_form);
		return true;
	}
}

void Headmaster::receiveForm(Form* p_form)
{
	if (p_form == nullptr)
		return;
	else
	{
		_formToValidate.push_back(p_form);
		std::cout << "Form received\n";
	}
}

void Headmaster::askProfessorsToTeach()
{
	StaffList* staffList = StaffList::getInstance();
	for (auto staff : staffList->getItems())
	{
		if (Professor* professor = dynamic_cast<Professor*>(staff))
		{
			std::cout << "Le professeur " << professor->getName() << " va faire un cours.\n";
			professor->doClass();
		}
	}
}