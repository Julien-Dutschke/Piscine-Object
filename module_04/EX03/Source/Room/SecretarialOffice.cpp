#include "../../Header/Room.hpp"


SecretarialOffice::SecretarialOffice() : Room()
{
	std::cout << "SecretarialOffice created\n";
	_type = RoomType::Secretaria;
}

SecretarialOffice::~SecretarialOffice()
{
	std::cout << "SecretarialOffice destroyed\n";
}