#ifndef __FORMTYPE_HPP__
# define __FORMTYPE_HPP__

#include "../Person/Person.hpp"

enum class FormType
{
	CoursFinished,
	NeedMoreClassRoom,
	NeedCoursCreation,
	SubscriptionToCours
};


class IForm
{
    protected:
        FormType _formType;
        bool _isSigned;
        Person* _signer;

    public:
        IForm() = delete;
        IForm(FormType p_formType) : _formType(p_formType){}
        void sign(Person* p_signer)
        {
            if (p_signer->getType() == Grade::Staff)
            {
                _signer = p_signer;
                _isSigned = true;
            }
        }
        virtual void execute() = 0;
};


class CoursFinishedForm : public IForm
{
    private:
    // le cours qui est fini

    public:
    CoursFinishedForm() : IForm(FormType::CoursFinished){}

        void execute()
        {
            // on retire le cours de la liste des cours
        }
};

class NeedMoreClassRoomForm : public IForm
{
    private:
    // un pointeur de salle de classe à ajouter

    public:
    NeedMoreClassRoomForm() : IForm(FormType::NeedMoreClassRoom){}
        void execute()
        {
            // on ajoute une salle de classe
        }
};

class NeedCoursCreationForm : public IForm
{
    private:
    // pointeur de cours à ajouter

    public:
    NeedCoursCreationForm() : IForm(FormType::NeedCoursCreation){}

        void execute()
        {
            // on ajoute un cours
        }
};

class SubscriptionToCoursForm : public IForm
{
    private:
    // pointeur de cours et d'étudiant

    public:
    SubscriptionToCoursForm() : IForm(FormType::SubscriptionToCours){}
        void execute()
        {
            // on ajoute un étudiant à un cours
        }
};


#endif // __FORMTYPE_HPP__