#ifndef SECTION_H
#define SECTION_H

class Section
{
private:
  int id;

public:
    Section();
    Section(int id);
    ~Section();
    int getId();
    void setId(int id);
};

#endif
