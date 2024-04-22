#include "GearLever.hpp"


void GearLever::reverse()
{
    _gear = -1;
}

void GearLever::shift_up()
{
    if (_gear == 5)
        return;
    _gear++;
}

void GearLever::shift_down()
{
    if (_gear == -1)
        return;
    _gear--;
}
// Compare this snippet from IgnitionSystem.cpp: