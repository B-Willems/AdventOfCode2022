#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

#define MAX_LINE_LENGTH 1000
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int main() {
    // init
    FILE *textfile;
    char line[MAX_LINE_LENGTH];
    int a =0;
    int t=0;

    // open textfile
    textfile = fopen("C:\\Users\\BramWillems\\Documents\\aoc\\day1_1.txt","r");

    // read file line by line
    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        // check if line is empty
        if (strcmp("\n", line) != 0) {
            // when the line is not empty, add it to the previous line
            a = a + strtol(line, NULL, 10);
        } else {
            // when the line is empty, calculate if it is the maximum amount of calories so far.
            t = max(t, a);
            a = 0;
        }
    }
    fclose(textfile);

    printf("the total calories held by the top elf is: %d", t);

    return 0;
}
