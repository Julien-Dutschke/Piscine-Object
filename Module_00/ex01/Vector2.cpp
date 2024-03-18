#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : _x(x), _y(y){
}

float Vector2::getX() const{
    return _x;
}

float Vector2::getY() const{
    return _y;
}

void Vector2::setX(float x){
    _x = x;
}

void Vector2::setY(float y){
    _y = y;
}

bool Vector2::operator==(const Vector2& other) const{

    if (this->_x == other._x && this->_y == other._y){
        return true;
    }
    return false;
}