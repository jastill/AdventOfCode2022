#include <iostream>
#include <fstream>
#include <algorithm>

#include "Elf.h"
#include "Backpack.h"

#define TOP_ELVES 3

using namespace std;

// The input file
ifstream inputFile;

std::vector<Elf *> elves;
std::vector<Backpack *> backpacks;

bool compareElves(Elf *e1, Elf *e2)
{
    return e1->getTotalCalories() > e2->getTotalCalories();
}

void day3()
{
    // Each line is a backpack.
    // The line is split in half for each compartment
    Backpack *backpack;

    // This is well dodgy coding assuming the line is 64 characters long.
    char line[64];
    while (inputFile.getline(line, 64))
    {
        cout << line << endl;
        // If the line is empty, it's a new elf.
        if (line[0] != '\0')
        {
            backpack = new Backpack(line);
            backpacks.push_back(backpack);
        }
    }
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

    day3();

    // Dispose of elves
    for (int i = 0; i < elves.size(); i++)
    {
        delete elves[i];
    }

    return 0;
}