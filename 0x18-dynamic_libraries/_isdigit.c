#include "main.h"

/**
 * _isdigit - checks whether input is a digit
 * @c: input to be checked
 * Return: 1 if c is digit, else 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
