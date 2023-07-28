#include "main.h"
/**
 * reverse_array - reverses integers in an array
 *
 * @a: array
 * @n: number of array elements
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i;
	int temp;

	for (i = 0; i < n--; i++)
	{
		temp = a[i];
		a[i] = a[n];
		a[n] = t;
	}
}
