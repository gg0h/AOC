#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 11 //141
#define IN_SIZE 10 //140
#define SEARCH  "XMAS"


void horizontal() {}
void diagonal_down () {}
void diagonal_up () {}
void vertical () {}
void transpose () {}

int main() {
    char grid[IN_SIZE][ARRAY_SIZE];
    for(int i =0; i < IN_SIZE; ++i) {
        scanf("%s", grid[i]);        
    }
    for(int i =0; i < IN_SIZE; ++i) {
        printf("%s\n", grid[i]);        
    }
    exit(EXIT_SUCCESS);
}
