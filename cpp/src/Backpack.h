#ifndef BACKPACK_H
#define BACKPACK_H

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
    std::string getContents();

    static char getCommonItemPriority(Backpack *b1, Backpack *b2, Backpack *b3);
};

#endif
