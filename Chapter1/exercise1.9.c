#include <stdio.h>
int main(){
	int c;
	int last_char;
	while ((c = getchar()) != EOF){
		if(!(last_char == ' ' && c == ' '))
			printf("%c", c);
		last_char = c;
	}
}
