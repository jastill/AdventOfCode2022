#include <iostream>
#include <fstream>
#include <algorithm>

#include "Elf.h"

#define TOP_ELVES 3

using namespace std;

bool compareElves(Elf *e1, Elf *e2)
{
    return e1->getTotalCalories() > e2->getTotalCalories();
}

int main(int argc, char *argv[])
{

    // Check we have an input file as a parameter
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    // The input file
    ifstream inputFile;

    // Open the input file
    inputFile.open(argv[1]);

    // Check the file opened correctly
    if (!inputFile)
    {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    std::vector<Elf*> elves;
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

    // Dipose of elves
    for (int i = 0; i < elves.size(); i++)
    {
        delete elves[i];
    }

    return 0;
}