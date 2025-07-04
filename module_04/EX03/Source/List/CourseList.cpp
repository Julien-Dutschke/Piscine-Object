#include "../../Header/List.hpp"

#include "../../Header/Course.hpp"

CourseList::CourseList()
{
}

CourseList::~CourseList()
{
    for (auto it = _items.begin(); it != _items.end(); )
	{
        delete *it;
        it = _items.erase(it);
    }
}

void CourseList::display() const 
{
	std::cout << "number of courses: " << _items.size() << std::endl;
	std::cout << "CourseList::display() called\n";
	for (Course *course : _items)
	{
		std::cout << "Course: " << course->getName() << std::endl;
	}	
}

// retourne le cours qui a le nom p_name et pas une copie
// retourne nullptr si le cours n'existe pas
Course* CourseList::getCourse(std::string p_name)
{
	for (Course *course : _items)
	{
		if (course->getName() == p_name)
			return course;
	}
	return nullptr;
}


