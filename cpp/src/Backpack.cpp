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
    this->contents = new string(items);

    int len = strlen(items) / 2;

    string substr = this->contents->substr(0, len);
    Compartment *compartment = new Compartment(substr);

    this->compartments.push_back(compartment);

    substr = this->contents->substr(len, len);
    compartment = new Compartment(substr);
    this->compartments.push_back(compartment);

    cout << "Backpack created" << this << endl;
}