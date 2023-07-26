#include <stdio.h>
#include "main.h"

/**
 * print_array - print the elements of the array
 *
 * @a: stores array elemnts
 * @n: helps loop through the array
 *
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i < n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
