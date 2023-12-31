#include "main.h"

/**
 * binary_to_uint - this converts a binary to unsigned int.
 * @b: this is a pointer to a string that contains a binary number
 *
 * Return: will return an unsigned int with decimal value or 0 if error
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int num;

	num = 0;
	if (!b)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		num <<= 1;
		if (b[i] == '1')
			num += 1;

	}
	return (num);
}
