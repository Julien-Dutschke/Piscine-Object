#ifndef FORM_HPP

#define FORM_HPP

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
	protected:
	FormType _formType;

	public :
	Form(FormType p_formType) : _formType(p_formType)
	{
	}

	virtual void execute() = 0;

};

class CourseFinishedForm : public Form
{
	private:

	public:
		CourseFinishedForm() : Form(FormType::CourseFinished){}
		void execute(){}
};

class NeedMoreClassRoomForm : public Form
{
	private:

	public:
		NeedMoreClassRoomForm() : Form(FormType::NeedCourseCreation){}
		void execute();
};

class NeedCourseCreationForm : public Form
{
	private:

	public:
		NeedCourseCreationForm() : Form(FormType::NeedCourseCreation){}
		void execute();
};

class SubscriptionToCourseForm : public Form
{
	private:

	public:
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse){}
		void execute();
};


enum class Event
{
	RingBell
};







#endif