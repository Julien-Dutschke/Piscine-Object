#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

#include <cmath>

class Vector2
{
    private:
        float _x;
        float _y;
    
    public:
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    Vector2(float x, float y);

    bool operator==(const Vector2& other) const;
};


#endif // __VECTOR2_HPP__