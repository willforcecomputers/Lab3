/*
 * function2.c
 *
 *  Created on: Oct 11, 2016
 *      Author: William
 */

#include <stdio.h>

int func2(int x, int y) {
	//function computers the bitwise exclusive-or of two numbers without using ^ and using only ~ and &.
	//

	int num1 = x;
	int num2 = y;
	int num3 = ~x;
	int num4 = ~y;
	int bitand12;
	int bitand34;
	int bitxor;

	bitand12 = num1 & num2;
	bitand34 = num3 & num4;
	bitxor = (~bitand34) & (~bitand12);

	return bitxor;
}

int main() {
	int x = 56666;
	int y = 23756;

	printf("func2(%d,%d)= [%d] Expecting [33174]\n", x, y, func2(x, y));

	return 1;
}
