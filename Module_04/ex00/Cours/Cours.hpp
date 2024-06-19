#ifndef __COURS_HPP__
# define __COURS_HPP__
#include <string>
#include <vector>

class Professor;
class Student;

class Cours
{
    private:
        std::string _name;
        Professor* _responsable;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;

    public:
        Cours(std::string p_name) : _name(p_name), _responsable(nullptr), _numberOfClassToGraduate(0), _maximumNumberOfStudent(30){}
        void assign(Professor* p_professor)
        {
            _responsable = p_professor;
        }
        void subscribe(Student* p_student)
        {
            //verifier si le cours est complet && si l'etudiant n'est pas deja inscrit
            if(_students.size() < _maximumNumberOfStudent && p_student->isSubscribed(this) == false)
                _students.push_back(p_student);
        }
};

#endif // __COURS_HPP__