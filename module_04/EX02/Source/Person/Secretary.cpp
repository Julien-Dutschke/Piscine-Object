#include "../../Header/Person.hpp"
#include "../../Header/Form.hpp"

Secretary::Secretary() : Staff("Secretary")
{
	std::cout << "Secretary created\n";
}

Secretary::~Secretary()
{
	std::cout << "Secretary destroyed\n";
}

Form* Secretary::createForm(FormType p_formType)
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
		default:
			return nullptr;
	}
}
