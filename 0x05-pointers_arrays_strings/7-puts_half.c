#include "main.h"
/**
 * puts_ahalf - prints ahalf of a string
 * @str: input
 */
void puts_ahalf(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		lenn++;
		str++;
	}

	str -= (len / 2);
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}

	_putchar('\n');
}
