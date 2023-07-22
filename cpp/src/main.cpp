#include <iostream>
#include <fstream>
#include <algorithm>

#include "Elf.h"
#include "Backpack.h"
#include "Priority.h"
#include "Section.h"

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
 * Day 4
 */
void day4()
{

  // Each line is a range of sections
  // The line is split in half for each section

  string line;
  while (inputFile.getline(line, 1000))
  {
    // If the line is empty, it's a new elfs backpack
    if (line[0] != '\0')
    {
      // A line is two ranges split by a comma
      // e.g. 1-3, 5-7

      vector <string> tokens;
      stringstream ss(line);

      string intermediate;

      while(getline(ss, line, ','))
      {
        tokens.push_back(intermediate);
      }

      // Printing the token vector
      for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';

    }
  }
  cout << "Day 4 overlapping" << endl;
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

  day4();

  // Dispose of elves
  for (int i = 0; i < elves.size(); i++)
  {
    delete elves[i];
  }

  return 0;
}
