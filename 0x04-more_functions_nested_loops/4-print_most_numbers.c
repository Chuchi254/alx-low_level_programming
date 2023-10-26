#include "main.h"

/**
 * print_most_numbers - prints number 0 to 9 expect 2 and 4
 */

void print_most_numbers(void)
{
	char count = '0';

	while (count <= '9')
	{
		if (count == '2' || count == '4')
		{
			count++;
			continue;
		}
		_putchar(count);
		count++;
	}
	_putchar('\n');
}
