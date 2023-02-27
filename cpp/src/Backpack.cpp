#include "Backpack.h"

#include <iostream>
#include "stdio.h"

#include "string.h"

using namespace std;

/**
 * Constructor
 */
Backpack::Backpack()
{
}

/**
 * Constructor
 * @param items The items in the backpack
 */
Backpack::Backpack(char *items)
{
    this->contents = new string(items);

    int len = strlen(items) / 2;

    string substr = this->contents->substr(0, len);
    Compartment *compartment = new Compartment(substr);

    this->compartments.push_back(compartment);

    substr = this->contents->substr(len, len);
    compartment = new Compartment(substr);
    this->compartments.push_back(compartment);
}

/**
 * Get Common Item Priority for 2 compartments
 */
int Backpack::getCommonItemPriority()
{
    int priority = 0;

    priority = this->compartments[0]->getCommonItemPriority(this->compartments[1]);

    return priority;
}

/**
 * Get Common Item Priority for 3 backpacks
 */
char Backpack::getCommonItemPriority(Backpack *b1, Backpack *b2, Backpack *b3) {
  // Iterate through each character in the first backpack
  for (int i = 0; i < b1->contents->length(); i++) {
    // Check if the character is in the other two backpacks

    if (b2->contents->find(b1->contents->at(i)) != string::npos && b3->contents->find(b1->contents->at(i)) != string::npos) {
      return b1->contents->at(i);
    }
  }
}

std::string Backpack::getContents()
{
    return *this->contents;
}
