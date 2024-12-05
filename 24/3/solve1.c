#include <stdio.h>
#include <stdlib.h>
#include <regex.h>


#define ARRAY_INIT_SIZE  20000
#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

int main() {
    char buffer[ARRAY_INIT_SIZE];  
    fgets(buffer, ARRAY_INIT_SIZE, stdin); 
    char *s = buffer;
    printf("%s\n", s);
    regex_t re;
    char pattern[100] = "mul\\([0-9]{1,3},[0-9]{1,3}\\)";
    regcomp(&re, pattern, REG_EXTENDED);

    regmatch_t rmt[1];
    int error, len;
    error = regexec(&re, s, ARRAY_SIZE(rmt), rmt, 0);
    while (error == 0) {    /* while matches found */
        len = rmt[0].rm_eo - rmt[0].rm_so;
        printf("substring = \"%.*s\"\n", len, s + rmt[0].rm_so);
        s += rmt[0].rm_eo;
        error = regexec(&re, s, ARRAY_SIZE(rmt), rmt, 0);
    }
    exit(EXIT_SUCCESS);
}
