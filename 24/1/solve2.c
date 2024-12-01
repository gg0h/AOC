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
    int ri ,li,count ,old_ri;
    ri = li = count = old_ri = 0;
    while(li < n && ri < n) {
        if (l[li] == r[ri]) {
	    old_ri = ri;
	    do{
    	        count += l[li];
	        ri++;
	    } while(l[li] == r[ri]);
	    ri = old_ri;
	    li++;
	} else if (l[li] < r[ri]) {
            li++;
	} else { 
	    ri++;
	}
    }
    return count;
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




