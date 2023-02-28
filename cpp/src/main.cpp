#include <iostream>
#include <fstream>
#include <algorithm>

#include "Elf.h"
#include "Backpack.h"
#include "Priority.h"

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

/**
 * Day 3
 */
void day3()
{
  // Each line is a backpack.
  // The line is split in half for each compartment
  Backpack *backpack;
  int priority = 0;
  int priority2 = 0;

  // This is well dodgy coding assuming the line is 64 characters long.
  char line[64];
  // TODO: fix the dodgy coding
  while (inputFile.getline(line, 64))
  {
    // If the line is empty, it's a new elfs backpack
    if (line[0] != '\0')
    {
      backpack = new Backpack(line);
      backpacks.push_back(backpack);
      Elf *elf = new Elf(backpack);

      priority += backpack->getCommonItemPriority();
    }


    // Now part 2, each group of three backpacks has a common value
    // Every 3 backpacks check for a common value
    if (backpacks.size() % 3 == 0)
    {
      // Check each backpack against the other two
      char commonChar = Backpack::getCommonItemPriority(backpacks[backpacks.size() - 3], backpacks[backpacks.size() - 2], backpacks[backpacks.size() - 1]);

      priority2 += Priority::getPriority(commonChar);
    }
  }
  cout << "Part 1 Priority: " << priority << endl;
  cout << "Part 2 Priority: " << priority2 << endl;
}

/**
 * Main entry point
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 *
 * Requires a single command line argument which is the input file.
 */
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
