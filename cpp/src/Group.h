#include <string>
#include <vector>

#ifndef GROUP_H
#define GROUP_H

#include "Elf.h"

class Group {
private:
  std::vector<Elf *> elves;
  std::string *contents;

public:
  Group();
  int getCommonItemPriority();
  void addElf(Elf *elf);
};

#endif
