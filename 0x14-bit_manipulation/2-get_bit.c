#include"main.h"

/**
 * get_bit - this will return the value of a bit at a given index.
 * @n: this is the number to check bits in
 * @index: this is the index at which to check bit
 *
 * Return: will the value of the bit, or -1 if there is an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int dvsr, confirm;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	dvsr = 1 << index;
	confirm = n & dvsr;
	if (confirm == dvsr)
		return (1);
	return (0);
}
