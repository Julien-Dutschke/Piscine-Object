#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <iostream>
#include <string>
#include <cmath>

class Shape
{
    protected :
    std::string _name;
    public :
    std::string name() const{
        return _name;
    }
    virtual double area() const = 0;
    ~Shape() = default;
};

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    os << "Shape Name: " << shape.name() << std::endl;
    os << "Area: " << shape.area() << std::endl;
    return os;
}


#endif // __SHAPE_HPP__