#include <string>

class Backpack
{
private:
    std::string *items;
    std::string *compartment1;
    std::string *compartment2;

public:
    Backpack();
    Backpack(char *items);
};