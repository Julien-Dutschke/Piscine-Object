#ifndef __HEADMASTER_HPP__
#define __HEADMASTER_HPP__

#include "Staff.hpp"
#include "Form.hpp"
#include <vector>

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	void receiveForm(Form* p_form);
};

#endif // __HEADMASTER_HPP