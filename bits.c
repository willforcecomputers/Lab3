/*
 * bits.c
 *
 *  Created on: Oct 11, 2016
 *      Author: William Metzger
 *  Create various function to solve puzzles with a limited toolset.
 */

#include <stdio.h>

int func1(int x, int y) {
	//this function computes the bitwise & of two numbers only using ~ and |.
	//To accomplish this, each number is applied a bitwise not(~) and then combined with a bitwise or(|), then another bitwise not is applied to the resulting number.
	int num1 = x;
	int num2 = y;
	int bitand;

	num1 = ~num1; //get binary ones compliment of num1
	num2 = ~num2; //get binary ones compliment of num3
	bitand = num1 | num2; //use binary OR operator to combine numbers
	bitand = ~bitand; //get ones compliment of combined value

	return bitand;
}

int func2(int x, int y) {
	//function computers the bitwise exclusive-or of two numbers without using ^ and using only ~ and &.
	//takes each variable and stores in both normal and ones-compliment form, then uses a bitwise & to combine, and then takes ones compliment of each combined variable and combines once more

	int num1 = x; //normal variable 1
	int num2 = y; //normal variable 2
	int num3 = ~x; //ones compliment variable 1
	int num4 = ~y; //ones compliment variable 2
	int bitand12;
	int bitand34;
	int bitxor;

	bitand12 = num1 & num2; //combines variable 1 and 2 using &
	bitand34 = num3 & num4; //combines ones compliment forms of 1 and 2 using &
	bitxor = (~bitand34) & (~bitand12); //combines the ones compliment of the combinations of variables 1 and 2

	return bitxor;
}

int func3(int x) {
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

	num = (bit32 << 24) + (bit24 << 16) + (bit16 << 8) + bit8; //recombine blocks of bits after extraction

	result = !num; //if result of extracted and combined blocks is greater than one, set to zero using logical !

	return !result; //if result is zero, return 1 using logical !
}

int func4(int x) {
	//Function takes a single int as input, then check whether all odd-numbered bit is set to 1 and if so, returns 1
	//takes input, divides into 4 8-bit blocks and applies a mask of 10101010 to transfer only odd bits, then checks for any 0's by using xor of mask

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

	bit8 = bit8 ^ mask; //check for zeroes by xor of mask
	bit16 = bit16 ^ mask; //check for zeroes by xor of mask
	bit24 = bit24 ^ mask; //check for zeroes by xor of mask
	bit32 = bit32 ^ mask; //check for zeroes by xor of mask

	num = (bit32 << 24) + (bit24 << 16) + (bit16 << 8) + bit8; //recombine blocks of bits after extraction and checking for zeroes

	result = !num; //if remaining value of all blocks combined is 0, set to one and return using logical !

	return result;
}

int main() {
	//int variables for run 1
	int x = 56666;
	int y = 23756;

	//int variables for run 2
	int a = 4097;
	int b = 42000;

	//int variables for run 3
	int g = 72157;
	int h = 38764;

	//int for function 4 testing
	int j = 2863311530;
	int k = 0xFFFFFFFF;

	//runs for function 1
	printf("func1(%d,%d)= [%d] Expecting [23624]\n", x, y, func1(x, y));
	printf("func1(%d,%d)= [%d] Expecting [0]\n", a, b, func1(a, b));
	printf("func1(%d,%d)= [%d] Expecting [4428]\n", g, h, func1(g, h));

	//runs for function 2
	printf("func2(%d,%d)= [%d] Expecting [33174]\n", x, y, func2(x, y));
	printf("func2(%d,%d)= [%d] Expecting [46097]\n", a, b, func2(a, b));
	printf("func2(%d,%d)= [%d] Expecting [102065]\n", g, h, func2(g, h));

	//runs for function 3
	printf("func3(%d)= [%d] Expecting [1]\n", x, func3(x));
	printf("func3(%d)= [%d] Expecting [1]\n", y, func3(y));
	printf("func3(%d)= [%d] Expecting [0]\n", a, func3(a));

	//runs for function 4
	printf("func4(%d)= [%d] Expecting [0]\n", x, func4(x));
	printf("func4(%d)= [%d] Expecting [1]\n", j, func4(j));
	printf("func4(%d)= [%d] Expecting [1]\n", k, func4(k));


	return 1;
}
