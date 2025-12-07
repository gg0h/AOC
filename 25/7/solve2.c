#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define EMPTY '.'
#define BEAM '|'
#define SPLIT '^'


int main() {

    char buffer[MAX_LINE_LEN];
    char *str;
    int iter = 0;
    long int row[MAX_LINE_LEN];

    fgets(buffer, MAX_LINE_LEN, stdin);

    while(buffer[iter] != '\0') {
        if(buffer[iter] == 'S') row[iter] = 1;
        else row[iter] = 0;
        iter++;
    }

    while(fgets(buffer, MAX_LINE_LEN, stdin)) { 
        printf("%s", buffer);
        iter = 0;
        while(buffer[iter] != '\0') {
            if (buffer[iter] == '^') {
                row[iter - 1] += row[iter];
                row[iter + 1] += row[iter];
                row[iter] = 0;
            }
            iter++;
        }
    }
    long int acm = 0;
    printf("\n");

    for (int i =0; i< iter; i++) {
        printf("i: %d value: %ld\n", i, row[i]);
        acm += row[i];
    }

    printf("timelines %ld\n", acm);
}