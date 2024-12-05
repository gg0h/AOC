#include <stdio.h>
#include <string.h>

#define ARRAY_INIT_SIZE  100


int row_index, safe, dec_flag, inc_flag, is_safe_result, slice_index, skip;
int sliced_row[100];

int is_safe(int *row, int n) {
    inc_flag = dec_flag = 1;
    for(int j = 1; j < n; ++j){
       if(row[j - 1] - row[j] <= 0|| row[j - 1] - row[j]  > 3 ) {
    	dec_flag = 0;
       }
       if(row[j] - row[j-1] <= 0 || row[j] - row[j-1] > 3) {
    	inc_flag = 0;
       }
    }
    if(inc_flag || dec_flag) { return 1; }
    return 0;
}


int main(){
    int row[100];
    char buffer[ARRAY_INIT_SIZE];
    safe = dec_flag = inc_flag = row_index = 0;
    while(fgets(buffer, ARRAY_INIT_SIZE, stdin)) {
        //printf("%s", buffer);
	const char s[2] = " ";
        char *token;
   
        token = strtok(buffer, s);
        row_index = 0;
        while( token != NULL ) {
           sscanf(token ,"%d", row + row_index);
	   //printf("%d", row[row_index]);
	   ++row_index;
           token = strtok(NULL, s);
        }
        is_safe_result = is_safe(row, row_index);
	if(is_safe_result ) safe++;
        else {
            skip = 0;
            while(skip < row_index) {
                slice_index = 0;
                for(int k =0; k < row_index; k++) {
                    if(skip == k)
                        continue;
                    sliced_row[slice_index] = row[k]; 
                    slice_index++;
                }
                for(int l = 0; l < row_index -1; l++)
                    printf("%d ", sliced_row[l]);
                printf("---\n");
                if(is_safe(sliced_row, slice_index)) {
                    safe++;
                    break;
                }
                else{
                    skip++;
                }
            }

            


        }

    }
    printf("Safe: %d\n", safe);
    return 0;
}




