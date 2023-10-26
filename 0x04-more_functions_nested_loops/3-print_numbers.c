#include "main.h"

/**
 * print_numbers - prints numbers from 0 to 9
 *
 * Return: void
 */

void print_numbers(void)
{
	char count;

	for (count = '0'; count <= '9'; count ++)
	{
		_putchar(count);
	}
	_putchar('\n');
}
