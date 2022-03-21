#include <stdio.h>
#include <ctype.h>
#include <string.h>
void expand(char s1[], char s2[]);
int should_expand(char next_c, char last_c);
int main(){
	char s1[] = "a-g-123-9BF-H-s-w-xZ33T-AB-d";
	char s2[100];
	memset(s2, 0, sizeof s2);
	printf("doing expand on string: \n%s\n", s1);
	expand(s1, s2);
	printf("%s\n", s2);
	return 0;
}
void expand(char s1[], char s2[]){
	char c, last_c, next_c, d;
	int i, j, k, se;
	for (i = j = 0; (c = s1[i]) != '\0'; i++){
		//printf("c: %c\n", c);
		switch (c){
			case '-':
				//printf("In '-'\n");
				next_c = s1[++i];
				se = should_expand(next_c, last_c);
				//printf("last_c: %c, next_c: %c, se: %d\n", last_c, next_c, se);
				if (se){
					for (last_c++; last_c <= next_c; last_c++){
						//printf("In for, last_c is: %c\n", last_c);
						s2[j++] = last_c;
					}
					c = --last_c;
					break;
				}
				else
					i--;  // don't break, put '-' in string.
			default:
				s2[j++] = c;
				break;
				
		}
		last_c = c;
		//printf("s2: %s\n", s2);
	}
}
/*
Check wether both last and next chars are:
1. digits, and next is higher or equal, return 1
2. alphabet, same case, and next is higher or equal, return 1
3. other cases, return 0
*/
int should_expand(char n, char l){
	if (isdigit(l) && isdigit(n) && l <= n)
		return 1;
	else if (isalpha(l) && isalpha(n) && isupper(l) == isupper(n) && l <= n)
		return 1;
	else
		return 0;
}
