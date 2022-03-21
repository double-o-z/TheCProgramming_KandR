#include <stdio.h>
#define CHARACTERS 52
#define LOWER_CHARS 26
main(){
	int nchars[CHARACTERS];
	int c, i, j;
	for (i = 0; i < CHARACTERS; ++i)
		nchars[i] = 0;
	while ((c = getchar()) != EOF){
		if (c >= 'a' && c <= 'z')
			++nchars[c-'a'];
		else if (c >= 'A' && c <= 'Z')
			++nchars[c-'A'+LOWER_CHARS];
	}
	printf("Histogram of frequency of different characters:\n");
	for (i = 0; i < CHARACTERS; ++i){
		if (nchars[i] > 0){
			if (i < LOWER_CHARS)
				printf("%c: ", 'a'+i);
			else
				printf("%c: ", 'A'+i-LOWER_CHARS);
			for (j = 1; j <= nchars[i]; ++j)
				putchar('=');
			putchar('\n');
		}
	}
}
