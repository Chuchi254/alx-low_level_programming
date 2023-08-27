#include "main.h"

/**
 * _print_rev_recursion - prints a string to the stdout in reverse
 * @s: stirng to be printed
 *
 * Return: void
 * On error, return -1 and set errno appropriately
 */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
	return;
	_putchar('\n');
}
