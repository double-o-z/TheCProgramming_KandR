#include <stdio.h>
#define LIM 1000
enum stop {NO, YES};
int main(){
	char s[LIM], c;
	int stop = NO, i = 0;
	
	while (!stop){
		stop = YES;
		if (i<LIM-1)
			if ((c=getchar()) != '\n')
				if (c != EOF){
					s[i] = c;
					stop = NO;
					++i;
				}
	}
	/*
	for (i=0; i<LIM-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	*/
	printf("string: %s\n", s);
}
