#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include <vector>
#include "Item.h"

class Compartment
{
private:
    std::vector<Item*> items;

public:
    Compartment();
    Compartment(std::string c);
    int getCommonItemPriority(Compartment *compartment);
};

#endif