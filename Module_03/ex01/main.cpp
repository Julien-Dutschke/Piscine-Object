#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

class Hat : public Article
{
    public:
    Hat(double price) : Article("Hat", price){};
    Hat* clone() { return new Hat(*this); };
};

class RTX : public Article
{
    public:
    RTX(double price) : Article("RTX", price){};
    RTX* clone() { return new RTX(*this); };
};

class DiceSett : public Article
{
    public:
    DiceSett(double price) : Article("DiceSett", price){};
    DiceSett* clone() { return new DiceSett(*this); };
};
