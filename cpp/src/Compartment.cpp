#include "Compartment.h"
#include <iostream>
#include "stdio.h"

using namespace std;

Compartment::Compartment()
{
}

Compartment::Compartment(string c)
{
    for (int i=0; i<c.length(); i++)
    {
        Item *item = new Item(c[i]);
        this->items.push_back(item);
    }
}

int Compartment::getCommonItemPriority(Compartment *compartment)
{
    int priority = 0;

    for (int i=0; i<this->items.size(); i++)
    {
        for (int j=0; j<compartment->items.size(); j++)
        {
            if (this->items[i]->getItem() == compartment->items[j]->getItem())
            {
                priority += this->items[i]->getPriority();
                cout << "Common item: " << this->items[i]->getItem() << endl;
                cout << "Priority: " << priority << endl;

                return priority;
            }
        }
    }

    return priority;
}