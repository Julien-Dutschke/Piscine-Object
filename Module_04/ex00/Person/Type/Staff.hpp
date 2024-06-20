#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include <iostream>

#include "Person.hpp"
#include "../../Form/FormType.hpp"
#include "../../Cours/Cours.hpp"

class Staff : public Person
{
private:

public:
	void sign(IForm* p_form)
    {
        p_form->sign(this);
    }
};


class Headmaster : public Staff
{
    private:
	std::vector<IForm*> _formToValidate;
	
    public:
	void receiveForm(IForm* p_form)
    {
        _formToValidate.push_back(p_form);
    }
};



class Professor : public Staff
{
	private:
		Cours* _currentCours;

	public:
		void setCours(Cours* p_Cours)
		{
			_currentCours = p_Cours;
		}

		Cours* getCours(){return _currentCours;}
		void assignCours(Cours* p_Cours){_currentCours = p_Cours;}
		void doClass()
        {
            std::cout << " Need to implement a method to do the class i think in Cours directly" << std::endl;
        }
		void closeCours()
        {
            std::cout << this->getName() << ": I finish the cours" << std::endl;
        }
};


class Secretary : public Staff
{
private:

public:
	IForm* createForm(FormType p_formType)
    {
        switch(p_formType)
        {
            case FormType::CoursFinished:
                return new CoursFinishedForm();
            case FormType::NeedMoreClassRoom:
                return new NeedMoreClassRoomForm();
            case FormType::NeedCoursCreation:
                return new NeedCoursCreationForm();
            case FormType::SubscriptionToCours:
                return new SubscriptionToCoursForm();
        }
    }
	void archiveForm()
    {
        std::cout << " Need to implement a method to archive the form" << std::endl;
    }
};


#endif // __STAFF_HPP__