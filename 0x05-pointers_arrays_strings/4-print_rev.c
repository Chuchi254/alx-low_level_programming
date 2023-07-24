#include "main.h"

/**
 * print_rev - prints a string in reverse
 *
 * @s: stores the string
 */

void print_rev(char *s)
{
	int length = 0;
	char *ptr = s;

	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}
}
