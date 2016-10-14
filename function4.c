/*
 * function4.c
 *
 *  Created on: Oct 13, 2016
 *      Author: William
 */

#include <stdio.h>

int func4(int x) {
	//Function takes a single int as input, then check whether any odd-numbered bit is set to 1 and if so, returns 1
	//takes input, divides into 4 8-bit blocks and applies a mask of 10101010 to transfer only odd numbered values of 1

	int num = x;
	int mask = 0xAA; //bitmask to extract only odd numbered bits
	int result;

	int bit8 = num; //block of bits 0 - 7
	int bit16 = num >> 8; //block of bits 8 - 15
	int bit24 = num >> 16; //block of bits 16 - 23
	int bit32 = num >> 24; //block of bits 24 - 31

	bit8 = bit8 & mask; //extract first 8 bits
	bit16 = bit16 & mask; //extract second block of 8 bits
	bit24 = bit24 & mask; //extract third block of 8 bits
	bit32 = bit32 & mask; //extract fourth block of 8 bits

	bit8 = bit8 ^ mask; //extract first 8 bits
	bit16 = bit16 ^ mask; //extract second block of 8 bits
	bit24 = bit24 ^ mask; //extract third block of 8 bits
	bit32 = bit32 ^ mask; //extract fourth block of 8 bits

	num = (bit32 << 24) + (bit24 << 16) + (bit16 << 8) + bit8; //recombine blocks of bits after extraction

	result = !num;

	return result;
}

int main() {

	int x = 0xFFFFFFFD;
	printf("func4(%d)= [%d] Expecting [1]\n", x, func4(x));

	return 1;
}
