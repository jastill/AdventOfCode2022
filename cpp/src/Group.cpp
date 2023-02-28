#include "Group.h"

Group::Group() {
    contents = new std::string("Hello, World!");
}	

int Group::getCommonItemPriority() {

   

    return 0;
}	

void Group::addElf(Elf *elf) {
    elves.push_back(elf);
}

Group::~Group() {
    delete contents;
}

