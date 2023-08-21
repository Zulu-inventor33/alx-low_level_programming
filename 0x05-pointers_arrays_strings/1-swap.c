#include "main.h"
/**
 * swap_int - swaps values of two integers
 * @a: integer of swap
 * @b: integer of swap
 */
void swap_int(int *a, int *b)
{
	int m;

	m = *a;
	*a = *b;
	*b = m;
}
