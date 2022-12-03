#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

char wrongItem(char* s1, char* s2) {
    char w;
    for (int i = 0; i < strlen(s1); i++) {
        for (int j = 0; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                w = s1[i];
                return (char) w;
            }
        }
    }
}

int calculatePriority(char item){
    if((int) item < 97){
        return (int) item - 38;
    }else{
        return (int) item - 96;
    }
}

int main() {
    // init
    FILE *textfile;
    char line[MAX_LINE_LENGTH];
    char item;
    int len;
    int totalPriority = 0;

    textfile = fopen("day3.txt","r");

    while(fgets(line, sizeof(line), textfile)) {
        len = strlen(line)/2;
        char* s1 = malloc(len+1); // one for the null terminator
        memcpy(s1, line, len);
        s1[len] = '\0';
        char* s2 = malloc(len+1); // one for the null terminator
        memcpy(s2, line+len, len);
        s2[len] = '\0';

        item = wrongItem(s1, s2);
        totalPriority = totalPriority + calculatePriority(item);

        // free memory
        free(s1);
        free(s2);
    }

    fclose(textfile);

    printf("The total priority of all items in both compartments is: %d", totalPriority);
    return 0;
}