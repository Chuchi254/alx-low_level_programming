#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - prints the lements of an array
 * @array: pointer to the first elment of the array
 * @left: starting index of the subarray
 * @right: ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_binary - recursively seraches for a value in a sorted array
 * @array: pointer to the first element of the array
 * @left: starting index of the subarray
 * @right: ending index of the subarray
 * @value: value to search for
 *
 * Return: the index where the value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);
	if (array[mid] >= value)
		return (recursive_binary(array, left, mid, value));
	return (recursive_binary(array, mid + 1, right, value));
}

/**
 * advanced_binary - searches for a value in a sorted array using advanced
 * binary search
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the index where the value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
