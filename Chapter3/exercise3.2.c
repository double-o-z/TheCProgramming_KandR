#include <stdio.h>
void escape(char s[], char t[]);
void escape_revert(char t[], char u[]);
int main (){
	char s[100] = "bamba\tbatman\nwow\0";
	char t[100];
	char u[100];
	printf("result of running escape() on %s\n", s);
	escape(s, t);
	printf("%s\n", t);
	printf("result of runnign escape_revert() on %s\n", t);
	escape_revert(t, u);
	printf("%s\n", u);
	return 0;
}
void escape(char s[], char t[]){
	int i, j;
	char c;
	for (i = j = 0; (c = s[i]) != '\0'; i++)
		switch (c) {
			case '\t': 
				t[j++] = '\\';
				t[j++] =  't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] =  'n';
				break;
			default:
				t[j++] = c;
				break;
		}
	t[j] = '\0';
}
void escape_revert(char t[], char u[]){
	int i, j;
	char c;
	char last_c = '0';
	for (i = j = 0; (c = t[i]) != '\0'; i++){
		switch (c) {
			case 'n':
			case 't':
				printf("In case 't' with char: %c and last_c: %c\n", c, last_c);
				if (last_c == '\\'){
					printf("In if\n");
					u[--j] = (c == 'n') ? '\n' : '\t';
					j++;
					last_c = c;
					break;
				}
			default:
				printf("In default with char: %c and last_c: %c\n", c, last_c);
				u[j++] = c;
				last_c = c;
				break;
		}
		printf("u: %s\n", u);
	}
	u[j] = '\0';
}
