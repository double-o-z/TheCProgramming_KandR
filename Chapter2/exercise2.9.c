#include <stdio.h>
int bitcount(signed x);
int main(){
	signed int x = 127;	// 0111 in two's complement (signed)
	int b = bitcount(x);  	// expect 3
	printf("bit count of signed int x: %d, is %d\n", x, b);
}

int bitcount(signed x){
	/* 
	Count bits in signed integer. 
	Each time we remove 1 from x, and & with itself, thus removing the right most bit. 
	When x is decreased by 1, the right most bit becomes zero, and some or the bits on its right might become 1.
	But by using &, we remove them because x has zeros on the right most bits of x-1.
	This simplfies the bit count because its cheaper them shifting x by 1 each iteration.
	Simply deleting a bit or decreasing x by 1 is cheaper.
	*/
	int b;
	for (b = 0; x != 0; x &= x -1)
		b++;
	return b; 
}
