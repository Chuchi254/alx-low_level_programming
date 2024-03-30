#include "main.h"

/**
 * _puts - prints a string to stdout
 * @s: string to be printed
 * Return: nothing
 */

void _puts(char *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			_putchar(s[i]);
			i++;
		}
		_putchar('\n');
	}
}
