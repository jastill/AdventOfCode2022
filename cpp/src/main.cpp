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

void day3()
{
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