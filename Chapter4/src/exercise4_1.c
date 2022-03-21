#include "exercise4_1.h"

char pattern[] = "ould";
int p_len = 4;

int getline_f(char s[], int lim){
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]){
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char s[], char t[], int len){
    int i, j, k;
    for (i = len-1; i >= 0; i--){
        for (j=i, k=p_len-1; k >= 0 && s[j]==t[k]; j--, k--)
            ;
        if (k < 0)
            return i-p_len+1;
    }
    return -1;
}

int exercise4_1(){
	char line[MAXLINE];
	int found = 0;
	int i, j;
	printf("Please write some lines. All lines with pattern: '%s', are printed back."
           "Finish by sending Ctrl+D.\n", pattern);
	while ((i = getline_f(line, MAXLINE)) > 0)
		if ((j = strrindex(line, pattern, i)) >= 0){
			printf("found pattern in line:\n%sat index: %d\n", line, j);
			found++;
		}
	return found;
}