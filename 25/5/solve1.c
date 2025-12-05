#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 128
#define NUM_RANGES 1048
#define NUM_INGREDIENTS 1048

struct range {
    long long int lower;
    long long int upper;
};

int main() {


    char buffer[MAX_LINE_LEN];

    struct range boundaries[NUM_RANGES];
    int iter = 0; 

    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        //printf("%s", buffer);
        if (*buffer == 0x0a) break; //skip after empty line
        sscanf(buffer, "%lld-%lld", &boundaries[iter].lower, &boundaries[iter].upper);
        printf("lower: %lld, upper: %lld\n", boundaries[iter].lower, boundaries[iter].upper);
        iter++;
    }
    long long int ingredient;
    int fresh_count = 0;
    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        sscanf(buffer, "%lld", &ingredient);
        //printf("%lld\n", ingredient);
        //printf("------------\n");

        for (int i = 0; i < iter; i++) {
            if (boundaries[i].lower <= ingredient && ingredient <= boundaries[i].upper) {
                fresh_count++;
                break;
            }
        }
    }
    printf("Fresh: %d\n", fresh_count);

    return 0;
}