#ifndef __SECRETARY_HPP__
#define __SECRETARY_HPP__

#include "Staff.hpp"
#include "Form.hpp"

class Secretary : public Staff
{
private:

public:
	Form* createForm(FormType p_formType);
	void archiveForm();
};

#endif // __SECRETARY_HPP