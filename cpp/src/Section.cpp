#include "Section.h"

Section::Section()
{

}

Section::Section(int id)
{
    this->id = id;
}

Section::~Section()
{

}

int Section::getId()
{
    return id;
}

void Section::setId(int id)
{
    this->id = id;
}


