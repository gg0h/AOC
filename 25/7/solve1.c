#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define BEAM '|'
#define SPLIT '^'

int main() {

    char buffer[MAX_LINE_LEN];
    char prev_buffer[MAX_LINE_LEN];
    char *str;
    int iter, count = 0;

    //first line
    fgets(prev_buffer, sizeof(prev_buffer), stdin);
    str = prev_buffer;

    while(*str != 'S') {
        str++;
    }
    *str = BEAM;

    while(fgets(buffer, sizeof(buffer), stdin)) {
        iter = 0;

        str = buffer;

        while(*(str + iter) != '\0') {
            //printf("prev: %c\n", prev_buffer[iter]);

            if(prev_buffer[iter] == BEAM) {
                if (buffer[iter] == SPLIT) {
                    buffer[iter - 1] = BEAM;
                    buffer[iter + 1] = BEAM;
                    count++;
                } else {
                    buffer[iter] = BEAM;
                }
            }
            
            iter++;
        }

        strncpy(prev_buffer, buffer, MAX_LINE_LEN);
        printf("%s", buffer);
    }

    printf("splits %d\n", count);
}