#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    // Check we have an input file as a parameter
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }


    // The input file
    ifstream inputFile;

    // Open the input file
    inputFile.open(argv[1]);

    // Check the file opened correctly
    if (!inputFile) {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }
    
    char line[64];
    while (inputFile.getline(line,64)) {


        cout << line << endl;
    }

    return 0;
}