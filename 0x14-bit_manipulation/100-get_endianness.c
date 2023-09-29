#include "main.h"

/**
 * get_endianness - this checks the endianness
 *
 * Return: will return 0 if big endian, and 1 if little endian
 */
int get_endianness(void)
{
	int y;
	char *x;

	y = 1;
	x = (char *)&y;
	return (*x);
}
