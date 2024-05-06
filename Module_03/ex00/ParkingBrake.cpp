#include "ParkingBrake.hpp"

void ParkingBrake::apply_force(int force)
{
    _force += force;
}

void ParkingBrake::apply_emergency_brakes()
{
    _force = 100;
}

