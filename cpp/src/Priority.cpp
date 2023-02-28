#include "Priority.h"

#include <iostream>
#include "stdio.h"

using namespace std;

Priority::Priority()
{
}

/**
 * @brief 
 * 
 * Lowercase item types a through z have priorities 1 through 26.
 * Uppercase item types A through Z have priorities 27 through 52.
 * 
 * @return int 
 */
int Priority::getPriority(char item)
{
    // It item is lower case.
    if (item >= 'a' && item <= 'z')
    {
        return (item - 'a') + 1;
    }
    if (item >= 'A' && item <= 'Z') 
    {
        return (item - 'A') + 27;
    }
    return -1;
}
