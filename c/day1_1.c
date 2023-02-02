#include "stdio.h"
#include "stdbool.h"


int main(int argc, char *argv[]){
  
  // Read the input file 

    FILE *fp;
    fp = fopen("../input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");

        return 1;
    }

    unsigned int i = 0;
    bool newLine = false;


    // Read char by char until end of line
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            // New line
            newLine = true;
        } else {
            i *= 10;
        }

        printf("%c", c);
    }

}

