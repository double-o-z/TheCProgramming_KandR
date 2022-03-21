#include <stdio.h>
#define MAX_STRING 1000
void squeeze(char s1[], char s2[]);
int main(){
	int i = 0;
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
	squeeze(s1,s2);
	printf("Result of s1 is now: %s\n", s1);
	return 0;
}

void squeeze(char s1[], char s2[]){
	int i, j, k;
	char c, d;
	for (i = j = 0; (c = s1[i]) != '\0'; i++){
		//printf("looking at s1 char: %c\n", c);
		for (k = 0; (d = s2[k]) != '\0' && d != c; k++)
			;
			//printf("looking at s2 char: %c\n", d);
		if (d != c){
			//printf("Not skipping this char: %c\n", s1[i]);
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}
