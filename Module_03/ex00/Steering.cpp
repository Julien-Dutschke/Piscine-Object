#include "Steering.hpp"

void Steering::turn_wheel(float angle)
{
    if (angle > 65)
        _angle = 65;
    else if (angle < -65)
        _angle = -65;
    else
        _angle = angle;
}

void Steering::straighten_wheels()
{
    _angle = 0;
}


// Path: ex00/Steering.hpp