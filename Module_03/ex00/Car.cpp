#include "Car.hpp"

void Car::start()
{
    std::cout << "Starting the car" << std::endl;
    _ignitionSystem.start();
}

void Car::stop()
{
    std::cout << "Stopping the car" << std::endl;
    _ignitionSystem.stop();
    _pedal.setSpeed(0);
}

void Car::accelerate(int speed)
{
    int actualGear = _gearLevel.getGear();

    if (_ignitionSystem.getStatus() == false)
        return;
    else if (actualGear == -1 && speed > 0)
    {
     std::cout << "Reverse gear activate" << std::endl;
     _pedal.accelerate(-speed);
    }
    else if (actualGear > 0)
    {
        std::cout << "Accelerating to " << speed  + _pedal.getSpeed() << " km/h" << std::endl;
        _pedal.accelerate(speed);
    }
    else
        return;
}


void Car::shift_gears_down()
{
    std::cout << "Shifting gears down" << std::endl;
    _gearLevel.shift_down();
}

void Car::shift_gears_up()
{
    std::cout << "Shifting gears up" << std::endl;
    _gearLevel.shift_up();
}

void Car::reverse()
{
    std::cout << "Reverse gear activate" << std::endl;
    _gearLevel.reverse();
}

void Car::turn_wheel(float angle)
{
    std::cout << "Turning the wheel to " << angle << " degrees" << std::endl;
    _steering.turn_wheel(angle);
}

void Car::straighten_wheels()
{
    std::cout << "Straightening the wheels" << std::endl;
    _steering.straighten_wheels();
}

void Car::apply_force_on_brakes(int force)
{
    std::cout << "Applying " << force << " force on the brakes" << std::endl;
    _parkingBrake.apply_force(force);
}

void Car::apply_emergency_brakes()
{
    _parkingBrake.apply_emergency_brakes();
}
