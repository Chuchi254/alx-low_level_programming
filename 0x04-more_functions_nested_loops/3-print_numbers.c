#include "main.h"

/**
 * print_numbers - prints numbers from 0 to 9
 *
 * Return: void
 */

void print_numbers(void)
{
	int count = 0;
	while (count <= 9)
	{
		_putchar(count);
		count++;
	}
}
