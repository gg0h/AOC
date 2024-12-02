#include <stdio.h>
#include <string.h>

#define ARRAY_INIT_SIZE  100

int main(){
    int row[100];
    int index, safe, dec_flag, inc_flag;
    char buffer[ARRAY_INIT_SIZE];
    safe = dec_flag = inc_flag = index = 0;
    while(fgets(buffer, ARRAY_INIT_SIZE, stdin)) {
        //printf("%s", buffer);
	const char s[2] = " ";
        char *token;
   
        token = strtok(buffer, s);
        index = 0;
        while( token != NULL ) {
           sscanf(token ,"%d", row + index);
	   //printf("%d", row[index]);
	   ++index;
           token = strtok(NULL, s);
        }
        printf("%d\n", index);
	inc_flag = dec_flag = 1;
	for(int j = 1; j < index; ++j){
           if(row[j - 1] - row[j] <= 0|| row[j - 1] - row[j]  > 3 ) {
		dec_flag = 0;
	   }
	   if(row[j] - row[j-1] <= 0 || row[j] - row[j-1] > 3) {
		inc_flag = 0;
	   }
	}
	if(inc_flag || dec_flag) { safe++; } 
    }
    printf("Safe: %d\n", safe);
    return 0;
}




