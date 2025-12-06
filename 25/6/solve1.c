#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ROW_SIZE 2096
#define NUM_ROWS 4
#define NUM_OP_ROWS
int main() {
    int numbers[NUM_ROWS][ROW_SIZE];
    char operators[ROW_SIZE];
    char buffer[ROW_SIZE * 2];

    char *end, *str;
    int store_idx;

    for (int i =0; i< NUM_ROWS; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        str = buffer;

        while (*str != '\0') {
            long value = strtol(str, &end, 10);

            if (str == end) {        // No number found → skip character
                str++;
                continue;
            }
            numbers[i][store_idx] = value;
            store_idx++;
            printf("%ld ", value);
            str = end;               // Move to end of parsed number
        }
        printf("\n");
        store_idx = 0;
    }

    fgets(buffer, sizeof(buffer), stdin);

    str = buffer;
    long int sum = 0, hold = 0;

    while (*str != '\0') {
        // Skip whitespace
        while (*str && isspace((unsigned char)*str)) str++;

        if (*str == '\0' || *str == '\n') break;

        if (*str == '*') {
            hold = numbers[0][store_idx];
            for (int k = 1; k < NUM_ROWS; k++) {
                hold *= numbers[k][store_idx];
            }
            sum += hold;
            store_idx++;
            
        } else if (*str == '+') {
            for (int k = 0; k < NUM_ROWS; k++) {
                sum += numbers[k][store_idx];
            }
            store_idx++;
        } else {
            printf("Unexpected character: '%c'\n", *str);
        }

        str++; // move to next character
    }
    printf("sum: %ld\n", sum);
    
    return 0;
}