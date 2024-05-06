#ifndef __THUESDAYDISCOUNT_HPP__
#define __THUESDAYDISCOUNT_HPP__

#include "command.hpp"

class ThuesdayDiscount : public Command
{
    public:
    double get_total_prince()
    {
        double ret = Command::get_total_prince();
        return ret* 0.9;
    };
};

#endif // __THUESDAYDISCOUNT_HPP__