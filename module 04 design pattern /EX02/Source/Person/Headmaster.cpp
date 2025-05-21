#include "../../Header/Person.hpp"
#include "../../Header/Form.hpp"

Headmaster::Headmaster() : Staff("Headmaster")
{
	std::cout << "Headmaster created\n";
}

Headmaster::~Headmaster()
{
	std::cout << "Headmaster destroyed\n";
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