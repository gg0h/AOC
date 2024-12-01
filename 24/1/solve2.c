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

int similarity(int l[], int r[], int n) {
    int sum, rp, temp, old_rp;
    rp = 0; sum = 0; temp = 0;
    for (int j = 0; j < n; ++j) {
	if (l[j] > r[rp]) {
            do{
              ++rp;
	    } while(l[j] > r[rp] && rp < n -1 );
	}
        if (l[j] < r[rp]) continue;
	if (l[j] == r[rp]) {
	    old_rp = rp;
	    do{
                temp++;
	        rp++;
	    } while(l[j] == r[rp] && rp < n-1);
	    rp = old_rp;
	}
	sum += l[j] * temp;
	temp = 0;
    } 
    return sum;
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

    int sim = similarity(left, right, i);
    printf("Similarity %d\n", sim);
    return 0;
}




