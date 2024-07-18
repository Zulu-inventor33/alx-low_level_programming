#include "search_algos.h"

int binary_search_recursion_helper(int *array, int value,
			    size_t low, size_t high);

/**
 * binary_search_recursion_helper - The helper to `advanced_binary`, recursively searches
 * for a value in an integer array
 * @array: The pointer to first element of array to seach
 * @value: The value to search for
 * @low: starting index in array
 * @high: The ending index in array
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */
int binary_search_recursion_helper(int *array, int value,
			    size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	mid = (low + high) / 2;
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mid] < value)
			return (binary_search_recursion_helper(array, value,
							mid + 1, high));
		if (array[mid] >= value)
			return (binary_search_recursion_helper(array, value,
							low, mid));
	}

	return (-1);
}

/**
 * advanced_binary - The Function that searches for a value in a sorted array of integers
 * using a binary search algorithm. Unlike `binary_search`, consistently
 * returns first appearance of `value` in array
 * @array: The pointer to first element of array to search
 * @size: number of elements in array
 * @value: The value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;

	if (!array)
		return (-1);

	return (binary_search_recursion_helper(array, value, low, high));
}
