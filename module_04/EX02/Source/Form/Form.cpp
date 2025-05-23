#include "../../Header/Form.hpp"

void Form::sign()
{
	_isSigned = true;
	std::cout << "Form has been signed\n";
}

bool Form::isSigned() const
{
	return _isSigned;
}

Form::Form(FormType p_formType) : _formType(p_formType), _isSigned(false)
{
	// std::cout << "Form created\n";
}

Form::~Form()
{
	// std::cout << "Form destroyed\n";
}

