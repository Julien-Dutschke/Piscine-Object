#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "shape.hpp"

#include <iostream>

class Rectangle : public Shape
{
    private:
    double _width;
    double _height;

    public :
    Rectangle(double width, double height) : _width(width), _height(height){
        _name = "Rectangle";
    }
    double area() const
    {
        return _width * _height;
    }
};



#endif