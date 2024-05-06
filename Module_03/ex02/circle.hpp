#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "shape.hpp"
#include <cmath>

#include <iostream>

class Circle : public Shape
{
    private:
    double _radius;

    public :
    Circle(double radius) : _radius(radius){
        _name = "Circle";
    }
    double area() const
    {
        return M_PI * exp2(_radius); 
    }
};

#endif // __CIRCLE_HPP__