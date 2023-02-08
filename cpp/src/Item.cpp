
#include "Item.h"
#include <iostream>
#include "stdio.h"

using namespace std;

Item::Item()
{
}

Item::Item(char c)
{
    this->item = c;
}

/**
 * @brief 
 * 
 * Lowercase item types a through z have priorities 1 through 26.
 * Uppercase item types A through Z have priorities 27 through 52.
 * 
 * @return int 
 */
int Item::getPriority()
{
    // It item is lower case.
    if (this->item >= 'a' && this->item <= 'z')
    {
        return (this->item - 'a') + 1;
    }
    if (this->item >= 'A' && this->item <= 'Z') 
    {
        return (this->item - 'A') + 1;
    }
    return -1;
}