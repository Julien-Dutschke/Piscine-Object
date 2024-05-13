#ifndef __THUESDAYDISCOUNT_HPP__
#define __THUESDAYDISCOUNT_HPP__

#include "command.hpp"

#include <ctime>

class ThuesdayDiscount : public Command
{
    public:
    double get_total_prince()
    {
        double ret = Command::get_total_prince();
        std::time_t now = time(0);
        std::tm *ltm = localtime(&now);
        if (ltm->tm_wday == 1)
            return ret* 0.9;
        else
            return ret;
    };
};

#endif // __THUESDAYDISCOUNT_HPP__