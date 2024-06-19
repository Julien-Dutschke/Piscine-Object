#ifndef __FORMTYPE_HPP__
# define __FORMTYPE_HPP__


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

    public:
        IForm(FormType p_formType) : _formType(p_formType){}

        virtual void execute() = 0;
};


class CoursFinishedForm : public IForm
{
    private:
    // le cours qui est fini

    public:
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
        void execute()
        {
            // on ajoute un étudiant à un cours
        }
};


#endif // __FORMTYPE_HPP__