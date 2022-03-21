#include <stdio.h>
#define MAX_WORD_LENGTH 20
main(){
	int nwords[MAX_WORD_LENGTH];
	int c, lw, i, j;
	for (i = 1; i <= MAX_WORD_LENGTH; ++i)
		nwords[i] = 0;
	lw = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			++nwords[lw];
			lw = 0;
		} else {
			++lw;
		}
	}
	printf("Histogram of words length:\n");
	for (i = 1; i<= MAX_WORD_LENGTH; ++i)
		if (nwords[i] > 0){
			printf("%d ", i);
			for (j = 1; j <= nwords[i]; ++j)
				putchar('=');
			putchar('\n');
		}
}
