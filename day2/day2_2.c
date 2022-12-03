#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int calculatePoints(const char *enemyChoice, const char *playerChoice){
    switch((int) *enemyChoice){
        case 65:
            switch((int) *playerChoice){
                case 88:
                    return 3;
                case 89:
                    return 4;
                case 90:
                    return 8;
            }
        case 66:
            switch((int) *playerChoice){
                case 88:
                    return 1;
                case 89:
                    return 5;
                case 90:
                    return 9;
            }
        case 67:
            switch((int) *playerChoice){
                case 88:
                    return 2;
                case 89:
                    return 6;
                case 90:
                    return 7;
            }
    }
}

int main() {
    // init
    FILE *textfile;
    char line[MAX_LINE_LENGTH];
    char *e[2500][2];
    char *tmp;
    int i = 0;
    int solution = 0, p;
    textfile = fopen("day2_1.txt","r");

    while(fgets(line, sizeof(line), textfile)) {
        tmp = strtok(line, " ");
        e[i][0] = strdup(tmp);
        tmp = strtok(NULL, " ");
        e[i][1] = strdup(tmp);
        p = calculatePoints(e[i][0], e[i][1]);

        solution = solution + p;
        i++;
    }

    fclose(textfile);

    printf("The total points scored using the updated strategy guide is: %d", solution);
}