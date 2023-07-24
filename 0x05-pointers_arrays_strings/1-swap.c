#include "main.h"

/**
 * swap_int - takes two integers and swaps their values
 *
 * @a: takes the value of b
 * @b: takes the value of a
 *
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
