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
		if (x <= v[mid]){
			high = mid-1;
			maybe_mid = mid;
		}
		else
			low = mid+1;
	}
	return (x == v[maybe_mid]) ? maybe_mid : -1;
}
/*
result of binsearch(x, v, n): 8 regular version, with double test in if-else
The elapsed time is 0.003599 seconds
result of binsearch(x, v, n): 8 specialized version, with single test in if-else
The elapsed time is 0.003305 seconds
clearly, its more efficient, even on binary search (O(logn)).
*/
