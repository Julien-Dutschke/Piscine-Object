//If you don't know what those 2 lines are, you should look for forward declaration
class Student;
class Professor;

/*
You're free to edit those class as much as you like, with the only limitation that the classes must perform the required interactions with one another.

You can change base pointer to smart one.
You can change return type to ... Whatever you like.

Anything, as long as you think it's smarter that what is currently writed in this file.
*/


class Classroom : public Room
{
private:
	Cours* _currentRoom;

public:
	Classroom();
	void assignCours(Cours* p_Cours);
};

class SecretarialOffice: public Room
{
private:
	std::vector<Form*> _archivedForms;

public:

};

class HeadmasterOffice : public Room
{
private:

public:

};

class StaffRestRoom : public Room
{
private:

public:

};

class Courtyard : public Room
{
private:

public:

};


class Staff : public Person
{
private:

public:
	void sign(Form* p_form);
};


class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	void receiveForm(Form* p_form);
};

class Secretary : public Staff
{
private:

public:
	Form* createForm(FormType p_formType);
	void archiveForm();
};


class Professor : public Staff
{
	private:
		Cours* _currentCours;

	public:
		void setCours(Cours* p_Cours)
		{
			_currentCours = p_Cours;
		}

		Cours* getCours(){return _currentCours;}
		void assignCours(Cours* p_Cours);
		void doClass();
		void closeCours();
};
