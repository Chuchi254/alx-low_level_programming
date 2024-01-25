#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - executing the functions in an array
 *
 * @array: array with functions
 * @size: the elements in the array
 * @action: pointer to function in the array
 *
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
