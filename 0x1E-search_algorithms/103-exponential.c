#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary - searches for a value in a sorted array of integers using
 * binary search
 * @array: pointer to the first element of the array to search
 * @low: the starting index of the subarray
 * @high: the ending index of hte subarray
 * @value: the value to search for
 *
 * Return: the index where the value is located, or -1 if not found
 */
int binary(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	while (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
		}
		printf("\n");

		mid = low + (high - low) / 2;
		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - search for a value in a sorted array of integers
 * using exponenetial search
 * @array: pointer to the first element of the array to search in
 * @size: the number of elments in the array
 * @value: the value to search for
 *
 * Return: the first index where the value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	return (binary(array, low, high, value));
}
