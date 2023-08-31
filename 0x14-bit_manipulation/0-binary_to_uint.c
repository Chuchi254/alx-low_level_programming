#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @b: string with binary number
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int decimalValue = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		decimalValue = 2 * decimalValue + (b[i] - '0');
	}

	return (decimalValue);
}
