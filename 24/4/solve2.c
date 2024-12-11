#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_SIZE 140 
#define ARRAY_SIZE IN_SIZE + 1


int found = 0;

struct point {
    int x;
    int y;
};

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;

    return temp;

}



int neighbours(char grid[IN_SIZE][ARRAY_SIZE], struct point pt) {
    // for(int y =0; y < IN_SIZE; ++y) 
    //     printf("%s\n", grid[y]); 
    int M, S;
    M = S = 0;
    for(int y = pt.y -1; y <= pt.y +1; y+=2) {
        for(int x = pt.x -1; x <= pt.x + 1; x+=2) {
            if ((y < 0 || y >= IN_SIZE) || (x < 0 || x >= ARRAY_SIZE -1 )) {
                return 0; 
            } 
            //printf("y: %d x: %d char %c \n", y, x, grid[y][x]);
            if (grid[y][x] == 'M') {
                printf("Found match M at %d %d from point %d %d\n", y, x, pt.y, pt.x);
                M++;
            } 

            if (grid[y][x] == 'S') {
                printf("Found match S at %d %d from point %d %d\n", y, x, pt.y, pt.x);
                S++;
            } 

        }
    }
    if(M == 2 && S == 2) {
        if(grid[pt.y -1][pt.x -1] == grid[pt.y + 1][pt.x + 1]) {
            printf("ret 0 S: %d M: %d from point %d %d\n", S, M, pt.y, pt.x);
            return 0;
        } else {
            printf("ret 1 S: %d M: %d from point %d %d\n", S, M, pt.y, pt.x);
            return 1;
        }
    }
    return 0;

}




int main() {

    char grid[IN_SIZE][ARRAY_SIZE];
    for(int i =0; i < IN_SIZE; ++i) {
        scanf("%s", grid[i]);        
    }
    for(int y =0; y < IN_SIZE; ++y) {
        for(int x =0; x < ARRAY_SIZE; x++) {
            if(grid[y][x] == 'A') {
                found += neighbours(grid, makepoint(x, y));
            }
        }
    }
    printf("Matches %d\n", found);
    exit(EXIT_SUCCESS);
}
