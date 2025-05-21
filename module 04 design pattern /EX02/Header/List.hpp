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
		StudentList();
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<StudentList>;

		~StudentList();
		void display() const ;
};



class RoomList : public AList<Room>, public Singleton<RoomList>
{
	protected:
		RoomList();
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<RoomList>;

		~RoomList();

		void display() const ;

};



class CourseList : public AList<Course>, public Singleton<CourseList>
{
	protected:
		CourseList();
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<CourseList>;

		~CourseList();
		void display() const ;

};



class StaffList : public AList<Person>, public Singleton<StaffList>
{
	protected:
		StaffList();
	public:
		// Déclare Singleton comme amie de cette classe
		friend class Singleton<StaffList>;

		~StaffList();
		void display() const;
};
#endif // __LIST_HPP__

