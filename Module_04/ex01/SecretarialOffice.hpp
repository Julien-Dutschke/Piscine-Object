#ifndef __SECRETARIALOFFICE_HPP__
#define __SECRETARIALOFFICE_HPP__

#include "Room.hpp"
#include <vector>

#include "Form.hpp"

class SecretarialOffice: public Room
{
private:
	std::vector<Form*> _archivedForms;

public:

};

#endif