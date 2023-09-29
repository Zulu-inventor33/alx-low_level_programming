#include "main.h"

/**
 * set_bit - this sets the value of a bit to 1 at a given index.
 * @n: this is the number to set
 * @index: the index at which to set bit
 *
 * Return: will return 1 if it worked, or -1 if an error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int num_set;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	num_set = 1 << index;
	*n = *n | num_set;
	return (1);
}
