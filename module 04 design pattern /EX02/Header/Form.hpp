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
	bool _isSigned;


	void sign();
	friend class Headmaster; //* Seul le Headmaster peut signer le formulaire

	public :
	Form(FormType p_formType);
	virtual ~Form();
	
	bool isSigned() const;
	virtual void execute() = 0;

};



class CourseFinishedForm : public Form
{
	private:
	std::string _nameCourseToFinished;
	

	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	friend class Headmaster; //* Seul le Headmaster peut signer le formulaire
	
	//creation interactive du formulaire
	CourseFinishedForm();
	~CourseFinishedForm();

	
	public:
		void execute() override;
};

class NeedMoreClassRoomForm : public Form
{
	private:
	
	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	friend class Headmaster; //* Seul le Headmaster peut signer le formulaire
	NeedMoreClassRoomForm();
	~NeedMoreClassRoomForm();
	
	public:
		void execute() override;
};

class NeedCourseCreationForm : public Form
{
	private:
	std::string _nameCourseToCreate;

	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	friend class Headmaster; //* Seul le Headmaster peut signer le formulaire

	NeedCourseCreationForm();
	~NeedCourseCreationForm();

	public:
		void execute() override;
};

class SubscriptionToCourseForm : public Form
{
	private:
	std::string _nameCourseToSubscribe;

	friend class Secretary; //* pour que seul la factory puisse creer le formulaire
	friend class Headmaster; //* Seul le Headmaster peut signer le formulaire

	SubscriptionToCourseForm();
	~SubscriptionToCourseForm();

	public:
		void execute() override;
};


enum class Event
{
	RingBell
};







#endif