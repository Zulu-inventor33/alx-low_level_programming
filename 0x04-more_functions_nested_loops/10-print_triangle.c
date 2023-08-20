#include "main.h"

/**
 * print_triangle - function prints a triangle, using the character #.
 * @size: The size of the triangle.
 */

void print_trinangle(int size)
{
	int hash, index;

	if (size > 0)
	{
		for (hash = 1 ; hash <= size; hash++)
		{
			_putchar(' ');
		}
		for (index = 
