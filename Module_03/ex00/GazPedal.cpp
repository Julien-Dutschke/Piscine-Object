#include "GazPedal.hpp"


void GazPedal::accelerate(int speed)
{
    _speed += speed;
}

void GazPedal::setSpeed(int speed)
{
    _speed = speed;
}

