// BitOperation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int getOneBitNumber(unsigned int n) 
// calculate how many one's bit in input number
{
	int res = 0;
	while (n) {
		res++;
		n &= (n - 1);// 
	}
	return res;
}

int findHightestOrderOneBit( unsigned int x )
// find highest order(MSB)
{
	int n;
	for ( n = 31; n > 0; n--) {
		if (x & (1 << n) )
			break;
	}
	//int n = 31;
	//if (x == 0) return -1;
	//if ((x >> 16) == 0) { n = n - 16; x = x << 16; }
	//if ((x >> 24) == 0) { n = n - 8; x = x << 8; }
	//if ((x >> 28) == 0) { n = n - 4; x = x << 4; }
	//if ((x >> 30) == 0) { n = n - 2; x = x << 2; }
	//if ((x >> 31) == 0) { n = n - 1; }
	return n;
}
 
int findLowestOrderOneBit( unsigned int x )
// find lowest order(LSB)
{
	return findHightestOrderOneBit(x & (~x+1));
}

void set_bit_range(unsigned int &x, int hi, int lo)
// set bit in range hi order to lo order
{
	unsigned int mask = (1 << (hi + 1)) - (1 << lo);

	x |= mask;
}

void clear_bit_range(unsigned int &x, int hi, int lo)
// set bit in range hi order to lo order
{
	unsigned int mask = (1 << (hi + 1)) - (1 << lo);

	x &= ~mask;
}

void set_bit(unsigned int &x, int n)
// set n-th bit to one
{
	x |= (1 << n);
}

void clear_bit(unsigned int &x, int n)
// set n-th bit to zero
{
	x &= ~( 1 << n );
}

void filp_bit(unsigned int &x, int n)
// filp n-th bit, 0 to 1, 1 to 0
{
	x ^= (1 << n);
}

bool check_bit(unsigned int x, int n)
// check if n-th bit is equal to one 
{
	return x & (1 << n) != 0;
}

unsigned int reverse(unsigned int x)
// reverse the bit
{
	unsigned int res = 0;
	for (int i = 0; i < 32; i++) {
		if (x & (1 << i)) {
			res |= (1 << (31 - i));
		}
	}
	return res;
}

void swap(int &x, int &y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

void toShowBinary( unsigned int x )
// show number in binary
{
	unsigned int mask = 0xf0000000;
	char *map[] = { "0000", "0001", "0010", "0011",
					"0100", "0101", "0110", "0111",
					"1000", "1001", "1010", "1011",
					"1100", "1101", "1110", "1111" };

	printf("Bin : ");
	for (int i = 7; i >= 0; i--, mask >>= 4) {
		printf( "%s ", map[ ( x & mask ) >> i * 4 ] );
	}
	printf("\n");
}

int main()
{
	int x = 0x12345678;
	printf("%d\n", x);
	printf("One bits number = %d\n", getOneBitNumber(x));
	printf("\n");

	int y = -25;
	toShowBinary(y);
	printf("MSB = %u\n", findHightestOrderOneBit(y));
	printf("LSB = %u\n", findLowestOrderOneBit(y));
	printf("\n");

	printf("x: %d, ", x);
	printf("y: %d\n", y);
	printf("after swap x, y \n");
	swap(x, y);
	printf("x: %d, ", x);
	printf("y: %d\n", y);
	printf("\n");

	int z = 0x12345678;
	printf("Dec : %d\n", z);
	toShowBinary(z);
	printf("MSB = %u\n", findHightestOrderOneBit(z));
	printf("LSB = %u\n", findLowestOrderOneBit(z));
	printf("\n");

	z = reverse(z);
	printf("%d\n", z);
	toShowBinary(z);
	printf("MSB = %u\n", findHightestOrderOneBit(z));
	printf("LSB = %u\n", findLowestOrderOneBit(z));
	printf("\n");

	unsigned int w = 0x0F0F0F0F;
	toShowBinary(w);
	set_bit(w, 14);
	toShowBinary(w);
	set_bit_range(w, 8, 4);
	toShowBinary(w);

	//int a = 2;
	//unsigned int &b = (unsigned int)a; // c2440

	system("pause");
    return 0;
}

