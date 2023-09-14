#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers -This is a function that prints numbers.
 * @n: This resepresents the number of arguments
 * @separator: This resepresents the seperator b/w the numbers
 * Return: Always 0.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	/* This creats a va_list to store the variable argument list */
	va_list my_nums;
	unsigned int count;

	/* initialize the valist for the number of arguments */
	va_start(my_nums, n);

	/* looping through all arguments stored in the valist */
	for (count = 0; count < n; count++)
	{
		printf("%d", va_arg(my_nums, unsigned int));
		if (count < (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	va_end(my_nums);
	printf("\n");
}
