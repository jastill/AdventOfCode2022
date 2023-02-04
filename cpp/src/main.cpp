#include <iostream>
#include <fstream>
#include <algorithm>

#include "Elf.h"

#define TOP_ELVES 3

using namespace std;

// The input file
ifstream inputFile;

std::vector<Elf *> elves;

bool compareElves(Elf *e1, Elf *e2)
{
    return e1->getTotalCalories() > e2->getTotalCalories();
}

void day1()
{
    Elf *elf;
    elf = new Elf();
    elves.push_back(elf);

    char line[64];
    while (inputFile.getline(line, 64))
    {
        cout << line << endl;
        // If the line is empty, it's a new elf.
        if (line[0] == '\0')
        {
            elf = new Elf();
            elves.push_back(elf);
        }
        else
        {
            elf->addCalories(atoi(line));
        }
    }

    int totalCalories = 0;

    // Sort the elves by calories
    std::sort(elves.begin(), elves.end(), compareElves);
    for (int i = 0; i < TOP_ELVES; i++)
    {
        std::cout << "Elf " << i << " has " << elves[i]->getTotalCalories() << " calories" << std::endl;
        totalCalories += elves[i]->getTotalCalories();
    }

    std::cout << "Total calories: " << totalCalories << std::endl;
}

char mapToRPS(char elf, char mine)
{

    // Nested array, Rock, Paper, Scissors values to map to
    // Lose Draw Win
    char gameMap[][3] = {
        {'C', 'A', 'B'},  // Rock
        {'A', 'B', 'C'},  // Paper
        {'B', 'C', 'A'}}; // Scissors

    // Map me to the correct value.
    // X means lose
    // Y means draw
    // Z means win
    return gameMap[elf - 'A'][mine - 'X'];
}

int calculateRockPaperScissors(char elf, char me)
{
    // Calculate the points
    int points = 0;

    int choicePointsMap[3] = {1, 2, 3};
    int gamePointsMap[][3] = {{3, 6, 0}, {0, 3, 6}, {6, 0, 3}};

    points += choicePointsMap[me - 'A'];
    points += gamePointsMap[elf - 'A'][me - 'A'];

    return points;
}

/**
 * @brief This is an ugly implementaiton that decodes the two sets of values.
 * but it is functional and simple to understand....
 *
 * @param elf
 * @param me
 * @return int
 */
int rps(char elf, char mine)
{
    std::cout << "Elf: " << elf << " Mine: " << mine << std::endl;

    char me = mapToRPS(elf, mine);

    std::cout << "Elf: " << elf << " Me: " << me << std::endl;

    return calculateRockPaperScissors(elf, me);
}

/**
 * @brief
 *
 */
void day2()
{
    int totalPoints = 0;
    char line[4];

    while (inputFile.getline(line, 4))
    {
        // If the line is empty, it's a new elf.
        if (line[0] != '\0')
        {
            char elf = line[0];
            char me = line[2];

            totalPoints += rps(elf, me);
        }
    }
    std::cout << "Total points: " << totalPoints << endl;
}

int main(int argc, char *argv[])
{

    // Check we have an input file as a parameter
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    // Open the input file
    inputFile.open(argv[1]);

    // Check the file opened correctly
    if (!inputFile)
    {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    day2();

    // Dispose of elves
    for (int i = 0; i < elves.size(); i++)
    {
        delete elves[i];
    }

    return 0;
}