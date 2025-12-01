#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 16

int main(){
    char buffer[MAX_LINE_LEN];
    int position = 50;
    int magnitude, temp_position;
    int password = 0;
    int flag = 1;
    while(fgets(buffer, MAX_LINE_LEN, stdin)) {
        
        if(buffer[0] == 'L') 
            magnitude = -1 * atoi(&buffer[1]);
        else
            magnitude = atoi(&buffer[1]);


        printf("MAGNITUDE %d\n", magnitude);
        printf("PASSWORD %d\n", password);
        printf("POSITION %d\n", position);

        password += abs(magnitude/100);
        magnitude %= 100;

        printf("NEW MAGNITUDE %d\n", magnitude);
        printf("==========\n");
        
        temp_position = position;
        temp_position += magnitude;

        if(temp_position == 0) {
            if(magnitude !=0)password++;
            position = temp_position;
        } else if(temp_position >= 100) {
            password++;
            position = temp_position - 100;
        } else if(temp_position < 0) {
            if(position != 0) password++;
            position = 100 + temp_position;
        } else {
            position = temp_position;
        }


    }
    printf("====\n");
    printf("a. %d\n",  0 % 100);
    printf("b. %d\n",  -1 % 100);
    printf("c. %d\n",  -100 % 100);
    printf("d. %d\n",  -101 % 100);
    printf("e. %d\n",  1 % 100);
    printf("f. %d\n",  100 % 100);
    printf("g. %d\n",  101 % 100);
    printf("====\n");
    printf("a1. %d\n",  0 / 100);
    printf("b1. %d\n",  -1 / 100);
    printf("c1. %d\n",  -100 / 100);
    printf("d1. %d\n",  -101 / 100);
    printf("e1. %d\n",  1 / 100);
    printf("f1. %d\n",  100 / 100);
    printf("g1. %d\n",  101 / 100);
    printf("====\n");

    printf("%d\n", password);
}