#ifndef __CAR_HPP__
#define __CAR_HPP__

#include "GazPedal.hpp"
#include "ParkingBrake.hpp"
#include "GearLever.hpp"
#include "Steering.hpp"
#include "IgnitionSystem.hpp"
#include <iostream>
#include <string>

class Car
{

    public:
    IgnitionSystem _ignitionSystem;
    Steering _steering;
    GearLever _gearLevel;
    ParkingBrake _parkingBrake;
    GazPedal _pedal;

    private:
    

    public:

    void start(); //* IgnitionSystem
    void stop(); //* IgnitionSystem

    void accelerate(int speed); //* _pedal

    void shift_gears_up(); //* GearLever
    void shift_gears_down(); //* GearLever
    void reverse(); //*GearLever


    void turn_wheel(float angle); //* Steering
    void straighten_wheels(); //* Steering;

    void apply_force_on_brakes(int force); //*ParkingBrake
    void apply_emergency_brakes(); //* ParkingBrake

};




#endif