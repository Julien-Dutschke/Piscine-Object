#include "Car.hpp"


int main()
{
    Car radio;

    std::string command;

    while (true)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "start")
            radio.start();
        else if (command == "stop")
            radio.stop();
        else if (command == "accelerate")
        {
            int speed;
            std::cout << "Enter the speed: ";
            std::cin >> speed;
            radio.accelerate(speed);
        }
        else if (command == "up")
            radio.shift_gears_up();
        else if (command == "down")
            radio.shift_gears_down();
        else if (command == "reverse")
            radio.reverse();
        else if (command == "turn_wheel")
        {
            std::cout << "Enter the angle: ";
            float angle;
            std::cin >> angle;
            radio.turn_wheel(angle);
        }
        else if (command == "straighten_wheels")
        {
            std::cout << "Straightening the wheels" << std::endl;
            radio.straighten_wheels();
        }
        else if (command == "apply_force_on_brakes")
        {
            int force;
            std::cout << "Enter the force: ";
            std::cin >> force;
            radio.apply_force_on_brakes(force);
        }
        else if (command == "apply_emergency_brakes")
            radio.apply_emergency_brakes();
        else if (command == "exit")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
    
}