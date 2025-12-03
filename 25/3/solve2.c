#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 128

int scan_largest(char* buffer, int n) {
    int largest_i = 0;
    for(int i = 0; i < n; i++) {
        largest_i = (buffer[i] > buffer[largest_i]) ? i : largest_i;
    }
    return largest_i;
}

int main(){
    char buffer[MAX_LINE_LEN];
    char slice[MAX_LINE_LEN];
    char digits[16] = {0};
    int offset, found_i;
    long long int sum = 0;
    long long int hold;
    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        offset = 0;
        for(int j = 0; j < 12; j++) {
            found_i = scan_largest(buffer + offset, strlen(buffer) - (13 - j) - offset + 1);
            digits[j] = buffer[offset + found_i];
            offset += found_i + 1;
        }
        sscanf(digits, "%lld", &hold);
        sum += hold;

        memset(digits, 0, sizeof(digits));
    }
    printf("SUM %lld\n", sum);
}