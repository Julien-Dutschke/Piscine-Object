#include "StaffMember.hpp"

Staff::Staff(std::string p_name) : Person(p_name, e_status::STAFF){}

void Staff::sign(Form* p_form)
{
    p_form->execute(this);
}

