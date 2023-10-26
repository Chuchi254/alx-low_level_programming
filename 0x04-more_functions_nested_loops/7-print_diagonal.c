#include "main.h"

/**
*print_diagonal- prints a diagonal
*
*@n:number of back slashes
*
*/

void print_diagonal(int n)
{
	int count;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		if (n == 1)
		{
			_putchar('\\');
			_putchar('\n');
		}
		for (count = 0; count < n - 1; count++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
}
