#ifndef FORM_HPP

#define FORM_HPP

#include "iostream"

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};



//* A titre d'information la classe Form respecte
//* le patern de classe de Command car
//* elle encapsule une requete en tant qu'objet
//* et permet de parametrer les clients
//* avec des requetes differentes
//* et de parametrer les requetes a executer
//* ici le client etant la classe Secretary
//* et la requete etant le formulaire a remplir
//* et l'invoker etant le Headmaster (ou le Staff)

class Form
{
	protected:

	FormType _formType;
	bool _isSigned = false;


	void sign(){
		_isSigned = true;
		std::cout << "Form has been signed\n";
	}

	friend class Headmaster; //* Seul les classes heritant de Staff peuvent acceder a la fonction sign

	public :
	Form(FormType p_formType) : _formType(p_formType)
	{
		std::cout << "Form created\n";
	}

	bool isSigned() const
	{
		return _isSigned;
	}

	virtual void execute() = 0;

};



class CourseFinishedForm : public Form
{
	private:
	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	CourseFinishedForm() : Form(FormType::CourseFinished){}

	public:
		void execute() override
		{
			if (isSigned() == false)
			{
				std::cout << "Form not signed\n";
				return;
			}
			std::cout << "CourseFinishedForm\n";
		}
};

class NeedMoreClassRoomForm : public Form
{
	private:
	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	NeedMoreClassRoomForm() : Form(FormType::NeedCourseCreation){}
	
	public:
		void execute() override
		{
			if (isSigned() == false)
			{
				std::cout << "Form not signed\n";
				return;
			}
			std::cout << "NeedMoreClassRoomForm\n";
		}
};

class NeedCourseCreationForm : public Form
{
	private:
	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	NeedCourseCreationForm() : Form(FormType::NeedCourseCreation){}

	public:
		void execute() override
		{
			if (isSigned() == false)
			{
				std::cout << "Form not signed\n";
				return;
			}
			std::cout << "NeedCourseCreationForm\n";

		}
};

class SubscriptionToCourseForm : public Form
{
	private:
	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse){}

	public:
		void execute() override
		{
			if (isSigned() == false)
			{
				std::cout << "Form not signed\n";
				return;
			}
			std::cout << "SubscriptionToCourseForm\n";
		}
};


enum class Event
{
	RingBell
};







#endif