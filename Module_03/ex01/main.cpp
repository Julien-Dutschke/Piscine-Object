#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

class Hat : public Article
{
    public:
    Hat(std::string name, double price) : Article(name, price){};
    Hat* clone() { return new Hat(*this); };
};

int main()
{
    Hat hat("Hat", 10);

    PackageReductionDiscount packageReductionDiscount;
    packageReductionDiscount.addArticle(&hat, 15);

    std::cout << "Total price with package reduction discount: " << packageReductionDiscount.get_total_prince() << std::endl;
}