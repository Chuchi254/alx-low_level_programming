#include "main.h"

/**
 * print_rev - prints a string in reverse
 *
 * @s: stores the string
 */

void print_rev(char *s)
{
	int length = 0, i;
	char *ptr = s;

	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
