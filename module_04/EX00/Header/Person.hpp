#ifndef PERSON_HPP

#define PERSON_HPP

# include <string>
# include <vector>
# include <iostream>

class Room;
class Course;
class Form;
class Person;
class Classroom;
class Form;
class Course;

enum class FormType;

class Person
{
	protected:
		std::string _name;
		Room* _currentRoom;

	public:
		Person(){std::cout << "Person created\n";}
		virtual ~Person() = default;
};


class Professor : public Person
{
	private:
		Course* _currentCourse;
	public:
		void assignCourse(Course* p_course);
		void doClass();
		void closeCourse();
};

class Student : public Person
{
	private:
		std::vector<Course*> _subscribedCourse;
	
	public:
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

class Staff : public Person
{
	protected:

	public:
		void sign(Form* p_form){(void) p_form;}
};


class Headmaster : public Staff
{
	private:
		std::vector<Form*> _formToValidate;
		
	public:
		void receiveForm(Form* p_form);
};

class Secretary : public Staff
{
	private:

	public:
		Form* createForm(FormType p_formType)
		{
			switch (p_formType)
			{
				case FormType::CourseFinished:
					return new CourseFinishedForm();
				case FormType::NeedMoreClassRoom:
					return new NeedMoreClassRoomForm();
				case FormType::NeedCourseCreation:
					return new NeedCourseCreationForm();
				case FormType::SubscriptionToCourse:
					return new SubscriptionToCourseForm();
			}
			return nullptr;
		}
		void archiveForm(){}
};


#endif
