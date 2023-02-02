#include <iostream>
#include <fstream>
#include "Elf.h"

using namespace std;

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

    int mostCalories = 0;

    // Open the input file
    inputFile.open(argv[1]);

    // Check the file opened correctly
    if (!inputFile)
    {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    Elf *elf;
    elf = new Elf();

    char line[64];
    while (inputFile.getline(line, 64))
    {

        cout << line << endl;
        // If the line is empty, it's a new elf.
        if (line[0] == '\0')
        {
            if (elf->getTotalCalories() > mostCalories)
                mostCalories = elf->getTotalCalories();
            delete elf;

            elf = new Elf();
        }
        else
        {
            elf->addCalories(atoi(line));
        }
    }

    if (elf->getTotalCalories() > mostCalories)
        mostCalories = elf->getTotalCalories();
    delete elf;
    std::cout << "Most calories: " << mostCalories << std::endl;

    return 0;
}