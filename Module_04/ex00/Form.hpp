#ifndef __FORM_HPP__
#define __FORM_HPP__


enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
private:
	FormType _formType;

public:
	Form(FormType p_formType){}

	virtual void execute() = 0;
};

#endif