#include "main.h"

/**
 * flip_bits - this counts the number
 * of bits to change to get from
 * one number to the other
 * @n: the first number
 * @m: the second number
 *
 * Return: wil return number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int start;
	unsigned long int end = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		start = end >> i;
		if (start & 1)
			count++;
	}

	return (count);
}
