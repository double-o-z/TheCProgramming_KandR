#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);
int main(){
	unsigned int x = 31; // 11111
	unsigned int y = 0;  // 00000
	unsigned int z = setbits(x, 3, 2, y);
	printf("x after setbits: %d\n", z); // 31-12 = 19.
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	// (y & 07)  			-- is the 3 left most bits of y
	// ~(~0 << n)  			-- gives me the the n right most bits turned on
	// (y & ~(~0 << n))  		-- gives me the n right most bits of y
	// (y & ~(~0 << n)) << (p+1-n)  -- gives me y's n bits from p location right adjusted
	// (~0 << p+1) | ~(~0 << n)
	return ((y & ~(~0 << n)) << (p+1-n)) | (x & ((~0 << p+1) | ~(~0 << n)));
}
