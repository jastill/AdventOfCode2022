#include "Backpack.h"
#include <iostream>
#include "stdio.h"

using namespace std;

Backpack::Backpack()
{
    cout << "Backpack created" << this << endl;
}

Backpack::Backpack(char *items)
{
    cout << "Backpack created" << this << endl;
    this->items = new string(items);

    int len = strlen(items) / 2;

    string substr = this->items->substr(0, len);
    this->compartment1 = new string(substr);
    substr = this->items->substr(len, len);
    this->compartment2 = new string(substr);

    cout << "Compartment 1: " << *this->compartment1 << endl;
    cout << "Compartment 2: " << *this->compartment2 << endl;
}