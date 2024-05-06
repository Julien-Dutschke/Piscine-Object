#ifndef __PACKAGE_REDUCTION_DISCOUNT_HPP__
#define __PACKAGE_REDUCTION_DISCOUNT_HPP__

#include "command.hpp"

class PackageReductionDiscount : public Command
{
    public:
    double get_total_prince()
    {
        double ret = Command::get_total_prince();
        if (ret >= 150)
            ret -= 10;
        return ret;
    };
};

#endif // __PACKAGE_REDUCTION_DISCOUNT_HPP__