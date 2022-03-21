#include <stdio.h>
#define MAX_STRING 1000
int any(char s1[], char s2[]);
int main(){
	int i = 0, res;
	char s1[MAX_STRING], s2[MAX_STRING], c;
	while ((c=getchar())!='\n' && c != EOF)
		s1[i++] = c;
	s1[i]='\0';
	//printf("Got string s1: %s\n", s1);
	i = 0;
	while ((c=getchar())!='\n' && c != EOF)
		s2[i++] = c;
	s2[i]='\0';
	//printf("Got string s2: %s\n", s2);
	res = any(s1,s2);
	printf("Result: %d\n", res);
	return 0;
}

int any(char s1[], char s2[]){
	int i, k;
	char c, d;
	for (i = 0; (c = s1[i]) != '\0'; i++){
		//printf("looking at s1 char: %c\n", c);
		for (k = 0; (d = s2[k]) != '\0' && d != c; k++)
			;
			//printf("looking at s2 char: %c\n", d);
		if (d != '\0'){
			//printf("Found s2 char: %c, in s1 at location: %d\n", s2[k], i);
			return i;
		}
	}
	return -1;
}
