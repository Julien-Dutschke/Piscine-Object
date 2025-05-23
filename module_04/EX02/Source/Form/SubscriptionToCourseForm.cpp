#include "../../Header/Form.hpp"
#include "../../Header/Person.hpp"
#include "../../Header/List.hpp"
#include "../../Header/Course.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
	std::cout << "Enter the name of the course to subscribe and the name of student: ";
	//std::cin >> _nameCourseToSubscribe;
	_nameCourseToSubscribe = "english";
	//std::cin >> _nameStudentToSubscribe;
	_nameStudentToSubscribe = "John Divers";
}

SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
	std::cout << "SubscriptionToCourseForm destroyed\n";
}

void SubscriptionToCourseForm::execute()
{
	if (isSigned() == false)
	{
		std::cout << "Form not signed\n";
		return;
	}

	std::cout << "Form SubscriptionToCourseForm activate\n";
	CourseList* courseList = CourseList::getInstance();
	Course* course = courseList->getCourse(_nameCourseToSubscribe);

	if (course == nullptr)
	{
		std::cout << "Course not found\n";
		return;
	}
	else
		std::cout << "Course found\n";
	StudentList* studentList = StudentList::getInstance();
	Student* student = studentList->getStudent(_nameStudentToSubscribe);
	if (student == nullptr)
	{
		std::cout << "Student not found\n";
		return;
	}
	else
		std::cout << "Student found\n";

	course->subscribe(student);
	std::cout << "Student " << _nameStudentToSubscribe << " subscribed to course " << _nameCourseToSubscribe << "\n";
}