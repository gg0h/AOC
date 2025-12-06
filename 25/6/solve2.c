#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ROW_SIZE 4192
#define NUM_ROWS 5

int main() {
    char rows[NUM_ROWS][ROW_SIZE];
    char buffer[ROW_SIZE];
    char num_parse[8];

    for (int k =0; k< NUM_ROWS; k++) {
        fgets(buffer, sizeof(buffer), stdin);
        strncpy(rows[k], buffer, ROW_SIZE - 1);
        rows[k][ROW_SIZE - 1] = '\0';
    }

    long int sum = 0, acm = 0;
    int parsed, end = 1, kill = 0;
    char *str;
    char op;

    for (int i =0; i< ROW_SIZE; i++) {
        if (rows[NUM_ROWS -1][i] != 0x20) op = rows[NUM_ROWS -1][i];

        str = num_parse;
        for (int j =0; j < NUM_ROWS -1; j++) {
            if (rows[j][i] != 0x20) end = 0;
            if (rows[j][i] == 0x0a) {kill = 1;end = 1;}
            //printf("%c\n", rows[j][i]);
            *str = rows[j][i];
            str++;
        }

        // end this calculation
        if (end) {
            printf("acm %ld\n", acm);
            sum += acm;
            acm = 0;
            if (kill) goto quit;

        } else {
            num_parse[7] = '\0';
            sscanf(num_parse, "%d", &parsed);
            printf("read: %d\n", parsed);
            printf("op: %c\n", op);

            if ( op == '*') {
                if(acm) acm *= parsed;
                else acm = parsed;

            } else if( op == '+') {
                acm += parsed;
            }
            
        }
        memset(num_parse, 0, sizeof(num_parse));
        end = 1;
        
    }
    quit:
    printf("sum: %ld\n", sum);
    
    return 0;
}