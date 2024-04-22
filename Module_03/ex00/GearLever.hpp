#ifndef __GEARLEVER_HPP__
#define __GEARLEVER_HPP__

class GearLever
{
    private:
    int _gear;

    public :
    GearLever() : _gear(0){}
    int getGear(){return _gear;}
    void reverse();
    void shift_up();
    void shift_down();

};

#endif