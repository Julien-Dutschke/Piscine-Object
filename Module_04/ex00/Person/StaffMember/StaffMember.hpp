#ifndef __STAFFMEMBER_HPP__
#define __STAFFMEMBER_HPP__

#include <iostream>
#include "../Person.hpp"


enum class Event
{
	RingBell
};

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
    Staff* _staff;

    public:
    Form(FormType p_formType) : _formType(p_formType), _staff(nullptr){};
    void execute(Staff* staff){std::cout << "Form executed" << std::endl; _staff = staff;}
};


class Staff : public Person
{
    private:

    public:
        Staff(std::string p_name) : Person(p_name, e_status::STAFF);
        void sign(Form* p_form);
};

class Secretary : public Staff
{
    private:

    public:
        // Form* createForm(FormType p_formType);
        // void archiveForm();
};

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	//void receiveForm(Form* p_form);
};

class Professor : public Staff
{
    // private:
	// Course* _currentCourse;

    // public:
	// void assignCourse(Course* p_course);
	// void doClass();
	// void closeCourse();
};


class CourseFinishedForm : public Form
{
private:
public:
};


class NeedMoreClassRoomForm : public Form
{
private:

public:
};

class NeedCourseCreationForm : public Form
{
private:

public:

};

class SubscriptionToCourseForm : public Form
{
private:

public:

};


#endif