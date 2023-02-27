#include "Elf.h"
#include <iostream>

/**
 * @brief Construct a new Elf:: Elf object
 * 
 */
Elf::Elf()
{
    std::cout << "Elf created" << this << std::endl;
    totalCalories = 0;
}

/**
 * @brief Construct a new Elf:: Elf object
 * 
 * @param c 
 */
Elf::Elf(int c)
{
    calories.push_back(c);
    totalCalories = c;
}

/**
 * @brief Construct a new Elf:: Elf object
 * 
 * @param b 
 */
Elf::Elf(Backpack *b) {
    this->backpack = b;
}

/**
 * @brief 
 * 
 * @param rps 
 */
void Elf::addRockPaperScissors(char rps)
{
    rockPaperScissors.push_back(rps);
}

/**
 * @brief Add an entry with calories
 *
 * @param c
 */
void Elf::addCalories(int c)
{
    calories.push_back(c);
    totalCalories += c;
}

/**
 * @brief Get the Total Calories object
 *
 * @return int
 */
int Elf::getTotalCalories(void)
{
    return totalCalories;
}

Backpack *Elf::getBackpack(void) {
    return this->backpack;
}