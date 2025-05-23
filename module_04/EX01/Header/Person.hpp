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
		bool operator==(const Person& p_person) const
		{
			return this == &p_person;
		}

		std::string getName() const {return _name;}
		void setName(std::string p_name) {_name = p_name;}
		Person(){std::cout << "Person created\n";}
		Person(const std::string& name) : _name(name), _currentRoom(nullptr) {}
		virtual ~Person() = default;
};


class Student : public Person
{
	private:
		std::vector<Course*> _subscribedCourse;
	
	public:
	Student(){};
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

class Staff : public Person
{
	protected:

	public:
	Staff() : Person("Staff") {}
		void sign(Form* p_form){(void) p_form;}
};

class Professor : public Staff
{
	private:
		Course* _currentCourse;
	public:
		void assignCourse(Course* p_course);
		void doClass();
		void closeCourse();
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
