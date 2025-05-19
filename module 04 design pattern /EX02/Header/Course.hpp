#ifndef COURSE_HPP
# define COURSE_HPP

# include <string>
# include <vector>

class Professor;
class Student;
class Room;


class Course
{
	private:
		std::string _name;
		Professor* _professor;
		std::vector<Student*> _students;
		size_t _numberOfClassToGraduate;
		size_t _maximumNumberOfStudent;

	public:
			Course(std::string p_name) : _name(p_name), _professor(nullptr), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0){}
			void assign(Professor* p_professor)
			{
				_numberOfClassToGraduate = 0;
				_professor = p_professor;                                                                                                                                                                                                                                                                                                                                                           
			}

			std::string getName() const
			{
				return _name;
			}

			Professor* getProfessor() const
			{
				return _professor;
			}

			void subscribe(Student* p_student)
			{
				if (_students.size() < _maximumNumberOfStudent)
				{
					_students.push_back(p_student);
				}
			}

			bool operator==(const Course& p_course) const
			{
				return _name == p_course._name;
			}
};

#endif 





