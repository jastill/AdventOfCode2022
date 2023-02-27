#ifndef ITEM_H
#define ITEM_H

#include <vector>

class Item
{
private:
    char item;

public:
    Item();
    Item(char c);
    int getPriority();
    char getItem();
};

#endif