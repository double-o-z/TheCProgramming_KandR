#include <stdio.h>
#define MAXLINE 80
int getline_f(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	char line[MAXLINE];
	
	while ((len = getline_f(line, MAXLINE)) > 0)
		if (len > MAXLINE)
			printf("Found line with length %d, first 100 chars are: %s", len, line);
	return 0;
}

int getline_f(char s[], int lim){
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	if (c != EOF && c!= '\n'){
		/* passed MAXLINE limit, but keep counting */
		++i;
		while ((c=getchar()) != EOF && c!='\n')
			++i;
	}
	return i;
}
