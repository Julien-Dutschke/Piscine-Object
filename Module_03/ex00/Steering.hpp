#ifndef __STEERING_HPP__
#define __STEERING_HPP__


class Steering
{
    private:
    float _angle;

    public :
    Steering() : _angle(0){}
    void turn_wheel(float angle);
    void straighten_wheels();
};

#endif
