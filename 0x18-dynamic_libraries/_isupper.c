#include "main.h"

/**
 * _isupper - checks whether input is uppercase
 * @c: input
 * Return: 1 if c is upper, else 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
