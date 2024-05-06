#ifndef __TRIANGLE_HPP__

#define __TRIANGLE_HPP__

#include "shape.hpp"

#include <iostream>

class Triangle : public Shape
{
    private:
    double _base;
    double _height;

    public :
    Triangle(double base, double height) : _base(base), _height(height){
        _name = "Triangle";
    }
    double area() const
    {
        return (_base * _height) / 2;
    }
};



#endif // __TRIANGLE_HPP__