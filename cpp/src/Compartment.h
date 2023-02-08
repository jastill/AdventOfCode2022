#include <vector>
#include "Item.h"
#include <string>


class Compartment
{
private:
    std::vector<Item*> items;

public:
    Compartment();
    Compartment(std::string c);
    int getCommonItemPriority(Compartment *compartment);
};
