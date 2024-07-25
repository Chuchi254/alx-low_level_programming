#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * min - finds the minimum of two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the minimum of a and b
 */
size_t min(size_t a, size_t b)
{
	return ((a < b) ? a : b);
}

/**
 * print_array - prints the array being searched between two indices
 * @array: pointer to the first element of the array
 * @left: left index
 * @right: right index
 */
void print_array(int *array, size_t left, size_t right)
{
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
}

/**
 * jump_search - searches for a value in a sorted array of integer using
 * jump search
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the first index where the value is located, or -1 if the value
 * is not present or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, i;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	prev = 0;

	while (array[min(step, size) - 1] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev = step;
		step += sqrt(size);
		if (prev >= size)
			return (-1);
	}

	print_array(array,prev, min(step, size) - 1);

	for (i = prev; i < min(step, size); i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
