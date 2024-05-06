#ifndef __GAZ_PEDAL_HPP__

#define __GAZ_PEDAL_HPP__

class GazPedal
{
    private:
    int _speed;

    public:
    GazPedal() : _speed(0){}
    int getSpeed(){return _speed;}
    void accelerate(int speed);
    void setSpeed(int speed);

};

#endif