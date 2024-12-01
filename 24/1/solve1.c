#include <stdio.h>


void bubble(int v[], int n) {
    int temp, swapped;
    do {
        swapped = 0;
	for(int i = 1; i < n; ++i) {
            if (v[i-1] > v[i]) {
                temp = v[i-1];
                v[i-1] = v[i];
		v[i] = temp;
		swapped = 1;
	    }
	}
    
    } while(swapped);
}


int main(){
    int left[1000];
    int right[1000];
    int i = 0;
    while(scanf("%d %d", left + i, right + i) == 2) {
        printf("l: %d r: %d\n", *(left + i), *(right + i));
	++i;
    }
    bubble(left, i);
    bubble(right, i);
    
    int sum, l, r, temp; 

    for(int j = 0; j< i; j++) {
	l = *(left + j);
	r = *(right + j);
        printf("l: %d r: %d\n", *(left + j), *(right + j));
        temp = l - r;
	if (temp < 0) 
	    temp = temp * -1;
        sum += temp;
    }

    printf("Sum: %d\n", sum);
    return 0;
}




