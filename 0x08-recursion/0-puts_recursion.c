#include "main.h"

/**
 * _puts_recursion - prints a string on the stdout
 * @s: string to be printed
 *
 * Return: 0 on success
 * On error return -1 and set errno appropriately
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar ('\n');
		return;
	}
	_putchar (*s);
	_puts_recursion(s + 1);
}
