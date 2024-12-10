#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_SIZE 140
#define ARRAY_SIZE IN_SIZE + 1
#define SEARCH  "XMAS"
#define SEARCH_SIZE 4 

void reverse(char* row) {
    char c;
    //printf("%s\n", row);
    for (int j =0; j < IN_SIZE/2; j++) {
        c = row[j];
        row[j] = row[IN_SIZE - 1 -j];
        row[IN_SIZE - 1 -j] = c;
    }
    //printf("%s\n", row);
    //printf("---\n");
}


int found = 0;
int hori_found = 0;

void horizontal(char* row) {

    for(int i = 0; i < ARRAY_SIZE - SEARCH_SIZE; i++) {
        if(strncmp(&row[i], SEARCH, SEARCH_SIZE) == 0) {
            //printf("FOUND\n");
            hori_found++;
        }
    }

}
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



void neighbours(char grid[IN_SIZE][ARRAY_SIZE], struct point pt, struct point *neighbours, char match_char ) {
    int neighbour_index = 0;
    // for(int y =0; y < IN_SIZE; ++y) 
    //     printf("%s\n", grid[y]); 

    for(int y = pt.y -1; y <= pt.y +1; y+=2) {
        //printf("%d\n", y);
        for(int x = pt.x -1; x <= pt.x + 1; x++) {
            if ((y < 0 || y >= IN_SIZE) || (x < 0 || x >= ARRAY_SIZE)) {
                neighbour_index++;
                continue;
            } 
            // right?
            if (grid[y][x] == match_char) {
                printf("Found match %c at %d %d from point %d %d\n", match_char, y, x, pt.y, pt.x);
                neighbours[neighbour_index] = makepoint(x, y);
            } 

            neighbour_index++;
        }
    } 

}




int main() {

    char *rev_holder;
    char grid[IN_SIZE][ARRAY_SIZE];
    for(int i =0; i < IN_SIZE; ++i) {
        scanf("%s", grid[i]);        
    }
    for(int y =0; y < IN_SIZE; ++y) {
        //printf("%s\n", grid[y]);        
        horizontal(grid[y]);
        rev_holder = strdup(grid[y]);
        reverse(rev_holder);
        horizontal(rev_holder);
        for(int x =0; x < ARRAY_SIZE; x++) {
            if(grid[y][x] == 'X') {
                //check neighbours
                for (int j = 0; j < 6; j++) {
                    struct point neighbour_points[6] = {
                        {-1,-1},   
                        {-1,-1},   
                        {-1,-1},   
                        {-1,-1},   
                        {-1,-1},   
                        {-1,-1}   
                    };
                    struct point temp;
                    neighbours(grid, makepoint(x, y), neighbour_points, 'M');
                    if(neighbour_points[j].x != -1) {
                        printf("found M on y:%d x:%d\n", neighbour_points[j].y, neighbour_points[j].x);
                        temp = neighbour_points[j];
                        memset(&neighbour_points[j], -1, sizeof(struct point));
                        neighbours(grid, temp, neighbour_points, 'A');
                        if(neighbour_points[j].x != -1) {
                            printf("found A on y:%d x:%d\n", neighbour_points[j].y, neighbour_points[j].x);
                            temp = neighbour_points[j];
                            memset(&neighbour_points[j], -1, sizeof(struct point));
                            neighbours(grid, temp, neighbour_points, 'S');
                            if(neighbour_points[j].x != -1) {
                                printf("found S on y:%d x:%d\n", neighbour_points[j].y, neighbour_points[j].x);
                            
                                found++;           
                            }       
                        }
                    }
                }
            }
        }
    }
    printf("Matches neighbour: %d horizontal: %d\n", found, hori_found);
    exit(EXIT_SUCCESS);
}
