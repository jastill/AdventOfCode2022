#ifndef ELF_H
#define ELF_H

#include <vector>
#include "Backpack.h"

class Elf
{
private:
    Backpack *backpack;
    std::vector<int> calories;
    std::vector<char> rockPaperScissors;
    int totalCalories;

public:
    Elf();
    Elf(Backpack *b);
    Elf(int c);
    int getTotalCalories(void);
    void addCalories(int c);
    void addRockPaperScissors(char rps);
    Backpack *getBackpack(void);
};

#endif