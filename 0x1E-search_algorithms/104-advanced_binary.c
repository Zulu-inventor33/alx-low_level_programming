#include "search_algos.h"

/**
  * binary_search_recursive - This Searches recursively for a value in a sorted
  *                             array of integers using binary search.
  * @array: The pointer to the first element of the [sub]array to search.
  * @left: A starting index of the [sub]array to search.
  * @right: ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: If the value is not present, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (binary_search_recursive(array, left, i, value));
	return (binary_search_recursive(array, i + 1, right, value));
}

/**
 * advanced_binary - This searches for a value in a sorted array of integers
 * using a binary search algorithm. Unlike `binary_search`, consistently
 * returns the first appearance of `value` in array
 * @array: A pointer to first element of array to search
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
