#include "main.h"

/**
 * _isalpha - checks whether input is an alphabet
 * @c: input to be checked
 * Return: 1 if c is alphabet, else 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
