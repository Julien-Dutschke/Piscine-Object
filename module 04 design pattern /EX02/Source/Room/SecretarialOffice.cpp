#include "../../Header/Room.hpp"


SecretarialOffice::SecretarialOffice() : Room()
{
	std::cout << "SecretarialOffice created\n";
	_type = "SecretarialOffice";
}

SecretarialOffice::~SecretarialOffice()
{
	std::cout << "SecretarialOffice destroyed\n";
}