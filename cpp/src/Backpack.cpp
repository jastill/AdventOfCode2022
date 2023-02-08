#include "Backpack.h"

#include <iostream>
#include "stdio.h"

#include "string.h"

using namespace std;

Backpack::Backpack()
{
}

Backpack::Backpack(char *items)
{
    this->contents = new string(items);

    int len = strlen(items) / 2;

    string substr = this->contents->substr(0, len);
    Compartment *compartment = new Compartment(substr);

    this->compartments.push_back(compartment);

    substr = this->contents->substr(len, len);
    compartment = new Compartment(substr);
    this->compartments.push_back(compartment);
}

int Backpack::getCommonItemPriority()
{
    int priority = 0;

    priority = this->compartments[0]->getCommonItemPriority(this->compartments[1]);

    return priority;
}
