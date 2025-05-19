#ifndef __PARTERN_HPP__
# define __PARTERN_HPP__

//classe de base Singleton

template <typename T>
class Singleton
{
	protected:
	static T* instance; //adresse de l'instance unique

	Singleton() {} // Constructeur privé pour empêcher l'instanciation directe
	Singleton(const Singleton&) = delete; // Supprimer le constructeur de copie
	Singleton& operator=(const Singleton&) = delete; // Supprimer l'opérateur d'assignation
	virtual ~Singleton() {} // Destructeur privé pour empêcher la destruction de l'instance

	public:
	// friend T; // Permet à la classe amie d'acceder au constructeur privé

	static T* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new T();
		}
		return instance;
	}

	// Méthode statique pour libérer l'instance
	static void destroyInstance()
	{
		delete instance;
		instance = nullptr;
	}
};

template <typename T>
T* Singleton<T>::instance = nullptr; // Initialisation de l'instance à nullptr

#endif