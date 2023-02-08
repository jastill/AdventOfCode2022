#include "Compartment.h"
#include <iostream>
#include "stdio.h"

using namespace std;

Compartment::Compartment()
{
    cout << "Compartment created " << this << endl;
}

Compartment::Compartment(string c)
{
    cout << "Compartment created " << c << endl;
    for (int i=0; i<c.length(); i++)
    {
        Item *item = new Item(c[i]);
        this->items.push_back(item);
    }
}