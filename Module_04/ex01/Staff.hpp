#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include "Person.hpp"
#include "Form.hpp"

class Staff : public Person
{
private:

public:
	void sign(Form* p_form);
};

#endif // __STAFF_HPP   