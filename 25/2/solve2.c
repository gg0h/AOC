#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
    
    char *ranges = NULL;
    char *token = NULL;
    char parse[32];
    size_t token_length;
    long int lefti, righti;
    unsigned long long count = 0;
    size_t len = 0;
    int chunk_size, start, end;
    getline(&ranges, &len, stdin);

    while ((token = strsep(&ranges, ",")) != NULL) {
        sscanf(token, "%ld-%ld", &lefti, &righti);
        for(long int i = lefti; i <= righti; i++) {
            sprintf(parse, "%ld", i);
            token_length = strlen(parse);         
            
            for (int step = 1; step < token_length; step++) {
                if (token_length % step == 0) {
                    chunk_size = token_length / step;
                    for (int j = 0; j < chunk_size - 1; j++) {
                        start = j * step;
                        end = (j+1) * step;
                        if(strncmp(&parse[start], &parse[end], step) != 0) {
                            goto bail;
                        }
                    }
                    count += i;
                    break;
                    
                }
                bail:;
                    
            }
                
        }
    }

    printf("count %lld\n", count);
    free(ranges);
}