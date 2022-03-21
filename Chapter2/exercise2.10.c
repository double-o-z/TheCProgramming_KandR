#include <stdio.h>
int lower(int c);
int main(){
	printf("lower result on: %c is %c\n", 'D', lower('D'));
	printf("lower result on: %c is %c\n", 'g', lower('g'));
	printf("lower result on: %c is %c\n", '5', lower('5'));
}
int lower(int c){
	return (c>= 'A' && c<= 'Z') ? (c + 'a' - 'A') : c;
}
