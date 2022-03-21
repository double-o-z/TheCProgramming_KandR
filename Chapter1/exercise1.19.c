#include <stdio.h>
#define MAXLINE 1000
int getline_f(char line[], int maxline);
void reverse(char line[], int len);
int main(){
	int len;
	char line[MAXLINE];
	
	while ((len = getline_f(line, MAXLINE)) > 0){
		reverse(line, len);
		printf("%s", line);
	}
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
	return i;
}

void reverse(char line[], int len){
	int i, temp, shortlen;
	shortlen = len-2;
	for (i = 0; i <= (shortlen/2); ++i){
		temp = line[shortlen-i];
		line[shortlen-i] = line[i];
		line[i] = temp;
	}
}
