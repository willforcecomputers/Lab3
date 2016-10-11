/*
 * function1.c
 *
 *  Created on: Oct 11, 2016
 *      Author: William
 */
#include <stdio.h>

int func1(int x, int y) {
	//this function computes the bitwise & of two numbers only using ~ and |.
	//To accomplish this, each number is applied a bitwise not(~) and then combined with a bitwise or(|), then another bitwise not is applied to the resulting number.
	int num1 = x;
	int num2 = y;
	int bitand;

	num1 = ~num1;
	num2 = ~num2;
	bitand = num1 | num2;
	bitand = ~bitand;

	return bitand;
}

int main() {

	printf("The bitwise & of 5 and 6 is %d\n", func1(5, 6));

	return 1;
}
