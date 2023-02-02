#include <vector>

class Elf
{
private:
    std::vector<int> calories;
    std::vector<char> rockPaperScissors;
    int totalCalories;

public:
    Elf();
    Elf(int c);
    int getTotalCalories(void);
    void addCalories(int c);
    void addRockPaperScissors(char rps);
};