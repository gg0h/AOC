#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char *ranges = NULL;
    char *token = NULL;
    char parse[32];
    size_t l;
    long int lefti, righti;
    unsigned long long count = 0;
    size_t len = 0;
    getline(&ranges, &len, stdin);


    while ((token = strsep(&ranges, ",")) != NULL) {
        sscanf(token, "%ld-%ld", &lefti, &righti);
        for(long int i = lefti; i <= righti; i++) {
            sprintf(parse, "%ld", i);
            l = strlen(parse);
            if(l % 2 != 0)
                continue;
            
            if(strncmp(&parse[0], &parse[l/2], l/2) == 0) {
                count += i;
            }
                
        }
    }
    printf("count %lld\n", count);
    free(ranges);
}