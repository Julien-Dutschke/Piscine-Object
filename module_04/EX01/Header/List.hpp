#ifndef __LIST_HPP__
#define __LIST_HPP__


#include <iostream>
#include <string>
#include <vector>



#include <algorithm>
#include <list>

#include "Person.hpp"
#include "Patern.hpp"

// This is a simple list class that uses std::list from the STL
template <class T>
class AList : public std::list<T>
{
	protected:	
		std::list<T> _items;

	public:
		//return true if the item is in the list
		bool isInList(const T& _item) const
		{
			bool found = false;
			for (const auto& item : _items)
			{
				if (item == _item)
				{
					found = true;
					break;
				}
			}
			return found;
		}

		void add(T& _item)
		{
			_items.push_back(_item);
		}

		void remove(T& _item)
		{
			_items.remove(_item);
		}

		virtual void display() const = 0;

		T& operator[](size_t index)
		{
			if (index >= _items.size())
			{
				throw std::out_of_range("Out of range");
			}
			auto it = std::next(_items.begin(), index);
			return *it;
		}

		typename std::list<T>::const_iterator begin() const
		{
			return _items.begin();
		}

		typename std::list<T>::const_iterator end() const
		{
			return _items.end();
		}
};



class StudentList : public AList<Student> , public Singleton<StudentList>
{
	protected:
		StudentList() {std::cout << "StudentList created\n";}
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<StudentList>;

		~StudentList() {std::cout << "StudentList destroyed\n";}
		void display() const 
		{
			std::cout << "number of students: " << _items.size() << std::endl;
			std::list<Student>::const_iterator it;
				std::cout << "StudentList::display() called\n";
			for (it = _items.begin(); it != _items.end(); ++it)
			{
				std::cout << "Student: " << it->getName() << std::endl;
				//std::cout << it << "\n";
			}	
		}
};

class RoomList : public AList<Room>, public Singleton<RoomList>
{
	protected:
		RoomList() {std::cout << "RoomList created\n";}
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<RoomList>;

		~RoomList() {std::cout << "RoomList destroyed\n";}
		void display() const 
		{
			std::cout << "number of rooms: " << _items.size() << std::endl;
			std::list<Room>::const_iterator it;
				std::cout << "RoomList::display() called\n";
			for (it = _items.begin(); it != _items.end(); ++it)
			{
				std::cout << "Room: " << it->getID() << std::endl;
				//std::cout << it << "\n";
			}	
		}

};

class CourseList : public AList<Course>, public Singleton<CourseList>
{
	protected:
		CourseList() {std::cout << "CourseList created\n";}
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<CourseList>;

		~CourseList() {std::cout << "CourseList destroyed\n";}
		void display() const 
		{
			std::cout << "number of courses: " << _items.size() << std::endl;
			std::list<Course>::const_iterator it;
				std::cout << "CourseList::display() called\n";
			for (it = _items.begin(); it != _items.end(); ++it)
			{
				std::cout << "Course: " << it->getName() << std::endl;
				//std::cout << it << "\n";
			}	
		}
};

class StaffList : public AList<Person>, public Singleton<StaffList>
{
	protected:
		StaffList() {std::cout << "StaffList created\n";}
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<StaffList>;

		~StaffList() {std::cout << "StaffList destroyed\n";}
		void display() const 
		{
			std::cout << "number of staff: " << _items.size() << std::endl;
			std::list<Person>::const_iterator it;
				std::cout << "StaffList::display() called\n";
			for (it = _items.begin(); it != _items.end(); ++it)
			{
				std::cout << "Staff: " << it->getName() << std::endl;
				//std::cout << it << "\n";
			}	
		}
};
#endif // __LIST_HPP__

