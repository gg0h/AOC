#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 16

int main(){
    char buffer[MAX_LINE_LEN];
    int position = 50;
    int magnitude;
    int password = 0;
    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        //printf("%s", buffer);
        
        if(buffer[0] == 'L') 
            magnitude = -1 * atoi(&buffer[1]);
        else
            magnitude = atoi(&buffer[1]);

        position = (position + magnitude) % 100;

        if(position < 0)
            position = 100 + position;
        

        if (position == 0)
            password++;
        

    }
    printf("====\n");
    printf("%d\n", -100 % 100);
    printf("====\n");

    printf("%d\n", password);
}
/**
I need the result to stay 0 <= x <= 99

50 - 68


*/