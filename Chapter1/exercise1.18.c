#include <stdio.h>
#define MAXLINE 1000
int getline_f(char line[], int maxline);

int main(){
	int len;
	int max;
	char line[MAXLINE];
	
	while ((len = getline_f(line, MAXLINE)) > 0){
		printf("%s", line);
	}
	return 0;
}

int getline_f(char s[], int lim){
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		if (i > 0){
			while ((i-1) >= 0 && (s[i-1] == ' ' || s[i-1] == '\t'))
				--i; /* remove trailing blanks and tabs */
			s[i] = c;
			++i;
		}
	}
	s[i] = '\0';
	if (c == '\n' && i == 0)
		++i; /* return 1 for blank lines, but with empty line for print */
	return i;
}
