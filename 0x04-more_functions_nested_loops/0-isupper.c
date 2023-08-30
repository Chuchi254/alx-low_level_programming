#include "main.h"

/**
 * _isupper - checks whether the input is upper case
 * @c: input
 *
 * Return: 0 on success
 */

int _isupper(int c)
{
	while (c >= 'A' &&  c <= 'Z')
		return (1);
	return (0);
}
