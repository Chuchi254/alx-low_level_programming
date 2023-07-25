#include "main.h"

/**
 * _atoi - function that converts a string to an integer
 * @s: stores string
 *
 * Return: digit on success
 *
 */

int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int digit;

	while (*s == ' ')
	{
		s++;
	}

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		digit = *s - '0';

		if ((result > (2147483647 - digit) / 10) && sign == 1)
		{
			return (0);
		}
		else if ((result > (2147483648 - digit) / 10) && sign == -1)
		{
			return (0);
		}
		result = result * 10 + digit;
		s++;
	}
	return (result * sign);
}
