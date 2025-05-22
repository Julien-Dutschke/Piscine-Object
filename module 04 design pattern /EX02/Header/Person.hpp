#ifndef PERSON_HPP

#define PERSON_HPP

# include <string>
# include <vector>
# include <iostream>

# include "Form.hpp"

class Room;
class Course;
class Form;
class Person;
class Classroom;
class Course;

class Person
{
	protected:
		std::string _name;
		Room* _currentRoom;

	public:
		bool operator==(const Person& p_person) const;

		std::string getName() const;
		void setName(std::string p_name);
		Person();
		Person(const std::string& name);
		virtual ~Person();
};


class Student : public Person
{
	private:
		std::vector<Course*> _subscribedCourse;
	
	public:
	Student();
	void leaveCourse(Course* p_course);
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

class Staff : public Person
{
	protected:

	public:
		Staff();
		Staff(std::string name);
		virtual ~Staff();
};

class Professor : public Staff
{
	private:
		Course* _currentCourse;
	
		public:
		Professor();
		virtual ~Professor();

		void assignCourse(Course* p_course);
		void doClass();
		void closeCourse();
		void setCourse(Course* p_course);
};


class Headmaster : public Staff
{
	private:
		std::vector<Form*> _formToValidate;
		

		void sign(Form* p_form){p_form->sign();}
	public:
		Headmaster();
		~Headmaster();

		bool validateForm(Form* p_form);
		bool signForm(Form* p_form);
		void receiveForm(Form* p_form);

};

class Secretary : public Staff
{
	private:

	public:
		Secretary();
		~Secretary();
		Form* createForm(FormType p_formType);
		void archiveForm(){}
};


#endif
