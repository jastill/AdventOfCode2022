#include <string>
#include <vector>

#include "Compartment.h"

class Backpack
{
private:
    std::vector<Compartment *> compartments;
    std::string *contents;

public:
    Backpack();
    Backpack(char *items);
    int getCommonItemPriority();
};