#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 128

int scan_largest(char* buffer, int n) {
    int largest_i = 0;
    int parse;
    for(int i = 0; i < n; i++) {
        largest_i = (buffer[i] > buffer[largest_i]) ? i : largest_i;
        //printf("CURRENT LARGEST %d\n", largest_i);
    }
    return largest_i;
}

int main(){
    char buffer[MAX_LINE_LEN];
    char slice[MAX_LINE_LEN];
    int first_digit_i, second_digit_i, new_start_i, sum;
    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        printf("%s", buffer);
        first_digit_i = scan_largest(buffer, strlen(buffer) - 2);
        printf("LARGEST INDEX %d\n", first_digit_i); // skip 0a and last character
        new_start_i = first_digit_i + 1;
        second_digit_i = scan_largest(buffer + new_start_i, strlen(buffer) - 1 - new_start_i);
        printf("LARGEST SECOND INDEX %d\n", new_start_i + second_digit_i);
        sum += 10 * (buffer[first_digit_i] - '0') + (buffer[new_start_i + second_digit_i] - '0');
        printf("SUM %d\n", sum);
        printf("=======\n");

    }
    printf("SUM %d\n", sum);
}