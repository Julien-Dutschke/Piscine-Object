#include "../../Header/Form.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
	std::cout << "Enter the name of the course to subscribe: ";
	//std::cin >> _nameCourseToSubscribe;
	_nameCourseToSubscribe = "english";
	std::cout << "the course to subscribe is : " << _nameCourseToSubscribe << std::endl;
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
	std::cout << "SubscriptionToCourseForm\n";
}