#include <stdio.h>
#include <time.h>
#define SIZE 1000000
#define BILLION 1000000000.0
int binsearch(int x, int v[], int n);
int main(){
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        int v[SIZE], x = 9;
        for (int i = 0; i<SIZE; i++)
                v[i]=i+1;
        printf("result of binsearch(x, v, n): %d\n", binsearch(x, v, SIZE));
        clock_gettime(CLOCK_REALTIME, &end);
        double time_spent = (end.tv_sec - start.tv_sec) +
                            (end.tv_nsec - start.tv_nsec) / BILLION;
        printf("The elapsed time is %f seconds\n", time_spent);
        return 0;
}
int binsearch(int x, int v[], int n){
	int low, high, mid, maybe_mid;

	low = 0;
	high = n-1;
	while (low <= high){
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}
