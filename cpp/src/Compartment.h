#include <vector>
#include "Item.h"

class Compartment
{
private:
    std::vector<Item*> items;

public:
    Compartment();
    Compartment(std::string c);
};