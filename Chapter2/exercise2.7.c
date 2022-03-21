#include <stdio.h>
unsigned invert(unsigned x, int p, int n);
int main(){
	unsigned int x = 873; // 1101101001 = 873
			      // 1100011001 = 793
	printf("x after invert(x, 4, 3): %d\n", invert(x, 4, 3)); // 793
	return 0;
}

/* returns x with n bits that begin at position p inverted, leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n){
							      		// 1101101001 x
							      		// 1100011001 result
	// first make a mask of 1's at bits other the the n after p:
	unsigned int left_mask = ~0 << n+p;    		      		// 1110000000
	unsigned int right_mask = ~(~0 << p);   	      		// 0000001111
	unsigned int full_mask = left_mask | right_mask;      		// 1110001111
	unsigned int reset_n_bits_of_x = x & full_mask;       		// 1100001001
	
	unsigned int revert_full_mask = ~(full_mask);	      		// 0001110000
	unsigned int only_n_bits_of_x = x & revert_full_mask;		// 0001100000
	unsigned int n_bits_of_x_revert = ~(only_n_bits_of_x); 		// 1110011111
	n_bits_of_x_revert = n_bits_of_x_revert & revert_full_mask;	// 0000010000
	return reset_n_bits_of_x | n_bits_of_x_revert;			// 1100011001
}
