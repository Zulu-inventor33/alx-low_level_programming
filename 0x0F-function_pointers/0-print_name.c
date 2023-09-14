#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - prints a given name
 * @name: name to be printed
 * @f: pointer to a given printing function
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
