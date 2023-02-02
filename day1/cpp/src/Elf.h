#include <vector>

class Elf {
private:
    std::vector<int> calories;
    int totalCalories;

public:
    Elf();
    Elf(int c);
   int getTotalCalories(void);
    void addCalories(int c); 

};