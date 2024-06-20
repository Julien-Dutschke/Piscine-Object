#ifndef __SECRETARIALOFFICE_HPP__
#define __SECRETARIALOFFICE_HPP__

#include "../Room.hpp"
#include <vector>
#include "../../Form/FormType.hpp"

class SecretarialOffice: public IRoom
{
    private:
	std::vector<IForm*> _archivedForms;

    public:

};


#endif // __SECRETARIALOFFICE_HPP__