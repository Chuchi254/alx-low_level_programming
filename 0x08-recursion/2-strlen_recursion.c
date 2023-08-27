#include "main.h"

/**
 * _strlen_recursion - computes the length of string
 * @s: string to be measured
 *
 * Return: 1 on success
 */

int _strlen_recursion(char *s)
{
	int count = 0;

	if (*s)
	{
		count ++;
		count += _strlen_recursion(s + 1);
	}
	return (count);
}
