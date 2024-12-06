#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>


#define ARRAY_INIT_SIZE  20000
#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

int main() {
    char buffer[ARRAY_INIT_SIZE];  
    fgets(buffer, ARRAY_INIT_SIZE, stdin); 
    char *s = buffer;
    regex_t re;
    char pattern[100] = "do\\(\\)|don't\\(\\)|mul\\([0-9]{1,3},[0-9]{1,3}\\)";
    regcomp(&re, pattern, REG_EXTENDED);
    regmatch_t rmt[1];
    int error, left, right, total, flag;
    total = 0;
    flag = 1;
    error = regexec(&re, s, ARRAY_SIZE(rmt), rmt, 0);
    while (error == 0) {    /* while matches found */
        if (strncmp(s + rmt[0].rm_so, "mul", 3) == 0) {
            /* mul */
            if(flag) {
                sscanf(s + rmt[0].rm_so, "mul(%d,%d)", &left, &right);
                total += left * right;
            }
        } else if (strncmp(s + rmt[0].rm_so, "do()", 4) == 0) {
            /* do */
            flag =1;
        } else if (strncmp(s + rmt[0].rm_so, "don't()", 7) == 0) {
            /* don't */
            flag = 0;
        }
        s += rmt[0].rm_eo;
        error = regexec(&re, s, ARRAY_SIZE(rmt), rmt, 0);
    }
    printf("Total: %d\n", total);
    exit(EXIT_SUCCESS);
}
