#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <iostream>
#include <limits>

void clearAllLists();

class tools
{
	public:

	void static printLine()
	{
		std::cout << "----------------------------------------\n";
	}
	
	//verifie si le formulaire est du type dans le quel on veut le caster
	template<typename T, typename U>
	static bool isOfType(const T* p_form)
	{
		if (p_form == nullptr)
			return false;
		if (dynamic_cast<const U*>(p_form) != nullptr)
			return true;
		else
			return false;
	}

    void  static cleanScrean()
    {
        std::cout << "\033[2J\033[1;1H"; // Clear the screen and move cursor to top-left
    }

	static void pressForContinue()
	{
		std::cout << "Appuyez sur Entrée pour continuer...\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin.get();
		if (std::cin.eof() || std::cin.fail()) 
		{
			std::cout << "Sortie du jeu.\n";
			clearAllLists();
			exit(0);
		}
	}
};

void testUnitaires();
void testPrintAllTypes();
void testPerson();
void testRoom();
void testRoomList();
void testCourseList();
void testStaffList();
void testSecretaryFactory();
void testFormsExecution();
void testStudentList();


#endif