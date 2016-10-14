/*
 * function3.c
 *
 *  Created on: Oct 13, 2016
 *      Author: William
 */

#include <stdio.h>

int func3(int x) {

	int num = x;
	int mask = 0xAA;
	int result;

	int bit8 = num;
	int bit16 = num >> 8;
	int bit24 = num >> 16;
	int bit32 = num >> 24;

	bit8 = bit8 & mask;
	bit16 = bit16 & mask;
	bit24 = bit24 & mask;
	bit32 = bit32 & mask;

	num = (bit32 << 24) + (bit24) + (bit16) + bit8;

	result = !num;

	return !result;
}

int main() {

	int x = 0xFFFF;
	printf("func3(%d)= [%d] Expecting [1]\n", x, func3(x));

	return 1;
}
