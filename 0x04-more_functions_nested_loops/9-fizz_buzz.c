#include <stdio.h>

/**
 * main - function prints the numbrs from 1-100, but for fmultiple numbers of 3
 * Fizz is printed instead of the number, for multiple numbers of five
 * Buzz, and for multiple of both three and five
 * Return: Always 0.
 */
int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{
		if (num % 15 == 0)
			printf("Fizzbuzz");

		else if (num % 3 == 0)
			printf("Fizz");

		else if (num % 5 == 0)
			printf("Buzz");
		else
			printf("%d", num);
		if (num < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
