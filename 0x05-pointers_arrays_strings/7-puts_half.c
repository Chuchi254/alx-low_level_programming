#include "main.h"

/**
 *puts_half - prints second half of hte string
 * @str: stores string
 */

void puts_half(char *str)
{
	int length = 0, i, start_index;
	char *ptr = str;

	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}
	start_index = (length - 1) / 2;

	for (i = start_index; i < length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
