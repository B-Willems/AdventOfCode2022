#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

char badgeItem(char* s1, char* s2, char* s3) {
    char b;
    for (int i = 0; i < strlen(s1); i++) {
        for (int j = 0; j < strlen(s2); j++) {
            for (int k = 0; k< strlen(s3);k++){
                if (s1[i] == s2[j] && s2[j] == s3[k]) {
                    b = (char) s1[i];
                    return (char) b;
                }
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
    char s[3][MAX_LINE_LENGTH];
    char item;
    int len;
    int totalPriority = 0;
    int q = 0;
    textfile = fopen("day3.txt","r");

    while(fgets(line, sizeof(line), textfile)) {
        //printf("%d line: %s\n", q, line);

        if(q < 2){
            strcpy(s[q], line);
            q++;
        }else{
            strcpy(s[q], line);
            printf("values in array: %s, %s, %s\n", s[0], s[1], s[2]);

            item = badgeItem(s[0], s[1], s[2]);
            printf("%c\n", item);
            totalPriority = totalPriority + calculatePriority(item);
            q = 0;
        }


    }

    fclose(textfile);

    printf("The total priority of all badges is: %d", totalPriority);
    return 0;
}