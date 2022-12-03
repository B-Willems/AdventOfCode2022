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
    int m[3] = {0,0,0};
    int result = 0;

    // do the whole shebang 3x
    for(int i=0;i<3;i++) {
        // open textfile
        textfile = fopen("day1_1.txt","r");
        // read file line by line
        while(fgets(line, MAX_LINE_LENGTH, textfile)){
            // check if line is empty
            if (strcmp("\n", line) != 0) {
                // when the line is not empty, add it to the previous line
                a = a + strtol(line, NULL, 10);
            } else {
                // when the line is empty, calculate if it is the maximum amount of calories so far.
                if (i == 0) {
                    t = max(t, a);
                } else {
                    if (max(t, a) < m[i - 1]) {
                        t = max(t, a);
                    }
                }
                a = 0;
            }
        }
        printf("%d", t);
        m[i] = t;
        result = result + m[i];
        t = 0;
        fclose(textfile);
    }

    printf("the total calories held by the top 3 elves is: %d", result);

    return 0;
}
