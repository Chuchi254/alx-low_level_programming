#include "main.h"

/**
 * _isdigit - checks whether input is a digit
 * @c: input
 * Return: 0 on success
 */

int _isdigit(int c)
{
	while (c >= '0' && c <= '9')
		return (1);
	return (0);
}
