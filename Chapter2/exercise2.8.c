#include <stdio.h>
unsigned rightrot(unsigned x, int n);
int main(){
	unsigned int x = 873; 								// 1101101001 = 873
	int n = 3;
	printf("x is %d, n is %d\n", x, n);
	printf("x after rightrot(x, 3): %d\n", rightrot(x, n));				// 0011101101 = 237
	return 0;
}

/* returns x rotated by n bits to the right. */
unsigned rightrot(unsigned x, int n){
											// 1101101001 original x 	873
											// 0011101101 wanted result 	237
											// 0001101111 actual result	111
	int x_bits = sizeof(x) * 8;
	//printf("x_bits: %d\n", x_bits);
	unsigned int x_n_shifted_right = x >> n; 					// 0001101101 x n shifted to the right
	//printf("x_n_shifted_right: %u\n", x_n_shifted_right);
	unsigned int x_n_right_most_bits = (~(~0 << n)) & x;				// 0000000001 x's right most n bits
	unsigned int n_bits_left_shifted = x_n_right_most_bits << (x_bits - n);		// 0010000000 right most n bits, left shifted
	unsigned int result = (x_n_shifted_right | n_bits_left_shifted);		// 0011101101 result 		237
	/* can be shorted.. simple left shift x by (x_bits - n) and use | with x right shifted by n: (x << (x_bits-n)) | (x >> n); */
	//return result;
	return (x << (x_bits-n)) | (x >> n); 
}
