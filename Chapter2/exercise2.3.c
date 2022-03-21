#include <stdio.h>
#include <ctype.h>
#include <string.h>
int htoi(char s[]);
int i = 0;
int main(){
	int result;
	extern int i;
	char s[1000], c;
	while ((c = getchar()) != '\n')
		s[i++] = c;
	s[i] = '\0';
	//printf("got hex number: %s\n", s);
	result = htoi(s);
	printf("result: %d\n", result);
	return 0;
}

int htoi(char s[]){
	extern int i;
	int hexPower = 1;
	char c;
	int res = 0;
	//printf("length of string: %d\n", i);
	for (--i; i >= 2; --i){  // Go from last char to second
		c = s[i];
		//printf("working on char: %c\n", c);
		if (isdigit(c))
			c = c - '0';
		else // a-f/A-F
			c = tolower(c) - 'a' + 10;
		//printf("weight of hex char: %d\n", c);
		res = res + (c * hexPower);
		//printf("res is currently: %d\n", res);
		hexPower = hexPower * 16;
		//printf("hexPower is currently: %d\n", hexPower);
	}
	return res;
}
