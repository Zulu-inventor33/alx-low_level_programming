#include "main.h"

/**
 * power - this function calculates (base ^ power)
 * @base: this is the base of the exponent
 * @pwr: this is power of the exponent
 *
 * Return: it will return value of (base ^ power)
 */
unsigned long int power(unsigned int base, unsigned int pwr)
{
	unsigned long int numb;
	unsigned int i;

	numb = 1;
	for (i = 1; i <= pwr; i++)
		numb *= base;
	return (numb);
}

/**
 * print_binary - this prints a number in binary notation
 * @n: the number to be printed
 *
 * Return: always returns void
 */
void print_binary(unsigned long int n)
{
	unsigned long int divisor, check;
	char flag;

	flag = 0;
	divisor = power(2, sizeof(unsigned long int) * 8 - 1);
	while (divisor != 0)
	{
		check = n & divisor;
		if (check == divisor)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag == 1 || divisor == 1)
		{
			_putchar('0');
		}
		divisor >>= 1;
	}
}
