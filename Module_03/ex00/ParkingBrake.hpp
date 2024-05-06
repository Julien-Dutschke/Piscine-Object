#ifndef __PARKINGBRAKE_HPP__
#define __PARKINGBRAKE_HPP__

class ParkingBrake
{
    int _force;

    public:
    ParkingBrake() : _force(0){}
    void apply_force(int force);
    void apply_emergency_brakes();
};

#endif