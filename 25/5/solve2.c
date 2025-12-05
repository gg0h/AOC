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
    int iter = 0, skip = 0; 

    long long int low, upp;

    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        //printf("%s", buffer);
        if (*buffer == 0x0a) break; //skip after empty line
        sscanf(buffer, "%lld-%lld", &low, &upp);
        for (int i = 0; i < iter; i++) {
            if (boundaries[i].lower <= low && low <=  boundaries[i].upper) low = boundaries[i].upper + 1;
            if (boundaries[i].lower <= upp && upp <=  boundaries[i].upper) upp = boundaries[i].lower - 1;
            if (low <= boundaries[i].lower && boundaries[i].upper <= upp  ) {
                boundaries[i].lower = low;
                boundaries[i].upper = upp;
                skip = 1;
                continue;
            }
            
        }
        if (upp < low)  {
            printf("SKIPPING lower: %lld, upper: %lld\n", low, upp);
            skip = 1; // range erased, skip
        }
        if(skip){
            skip = 0;
            continue;
        }
        boundaries[iter].lower = low;
        boundaries[iter].upper = upp;
        printf("lower: %lld, upper: %lld, difference (inc), %lld\n", boundaries[iter].lower, boundaries[iter].upper, boundaries[iter].upper - boundaries[iter].lower + 1);
        
        iter++;
    }
    unsigned long long int fresh_count = 0;
    for (int i = 0; i < iter; i++) {
        fresh_count += boundaries[i].upper - boundaries[i].lower + 1;
    }
    printf("Fresh: %lld\n", fresh_count);

    return 0;
}