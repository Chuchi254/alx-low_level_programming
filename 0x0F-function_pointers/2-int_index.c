#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - a function that searches for an integer within an array
 *
 * @array: array 
 * @size: number of elements in array
 * @cmp: pointer to function to be used to compare values
 *
 * Return: index of first element that cmp does not return 0
 * else: returns -1
 */

int int_index(int *array, int size, int(*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
