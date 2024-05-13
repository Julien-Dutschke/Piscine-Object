#include "shape.hpp"

#include "shape.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

int main()
{
    Circle c(5);
    Triangle t(5, 5);
    Rectangle r(5, 5);

    std::cout << c << std::endl;
    std::cout << t << std::endl;

    // std::cout << "now a proof the rule L of SO[L]ID is working\n" << std::endl;

    // Shape* shapes[] = {&c, &t, &r};

    // std::cout << *shapes[0] << std::endl;
    // std::cout << *shapes[1] << std::endl;
    // std::cout << *shapes[2] << std::endl;
    return 0;    
}