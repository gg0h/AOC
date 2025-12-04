#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_SIZE 140
#define ARRAY_SIZE IN_SIZE + 1

    


int main() {

    char grid[IN_SIZE][ARRAY_SIZE];
    for(int i =0; i < IN_SIZE; ++i) {
        scanf("%s", grid[i]);
        //printf("%s\n", grid[i]);  
    }
    int left = 1, right = 1, above = 1, below = 1, count = 0, found = 0;


    for(int i = 0; i < IN_SIZE; i++){
        for(int j =0; j< ARRAY_SIZE; j++) {
            
            if (grid[i][j] == '@') {
                            // turn off check flags for perimiter
                if (i == 0) {
                    above = 0;
                }
                if (j == 0) {
                    left = 0;
                }
                if (i == IN_SIZE - 1) {
                    below = 0;
                }
                if (j == IN_SIZE) {
                    right = 0;
                }
                
                //printf("i %d j %d\n", i, j);
                if (above) {
                    if (grid[i-1][j] == '@') count++;
                    if (right) {
                        if (grid[i-1][j+1] == '@') count++;
                    }

                    if (left) {
                        if (grid[i-1][j-1] == '@') count++;
                    }

                }

                if (right) {
                    if (grid[i][j+1] == '@') count++;
                }

                if (left) {
                    if (grid[i][j-1] == '@') count++;
                }

                if (below) {
                    if (grid[i+1][j] == '@') count++;
                    if (right) {
                        if (grid[i+1][j+1] == '@') count++;
                    }

                    if (left) {
                        if (grid[i+1][j-1] == '@') count++;
                    }

                }

                if(count < 4) {
                    found++;
                }

                left = 1, right = 1, above = 1, below = 1, count = 0;
            }
            

        }
    }


    printf("found: %d\n", found);




}
/**


*/