#include "../../Header/Room.hpp"

HeadmasterOffice::HeadmasterOffice() : Room()
{
	std::cout << "HeadmasterOffice created\n";
	_type = RoomType::HeadmasterOffice;
}

HeadmasterOffice::~HeadmasterOffice()
{
	std::cout << "HeadmasterOffice destroyed\n";
}