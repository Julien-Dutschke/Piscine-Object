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
			Course(std::string p_name);
			virtual ~Course();
			void assign(Professor* p_professor);

			std::string getName() const;

			Professor* getProfessor() const;

			void subscribe(Student* p_student);

			bool operator==(const Course& p_course) const;
			void stop();
};

#endif 
