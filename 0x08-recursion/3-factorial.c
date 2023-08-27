#include "main.h"

/**
 * factorial - calculates the factorial of a number
 * @n: number whose factorial is computed
 * Return: factorial of the number
 */

int factorial(int n)
{
	if (n > 0)
	{
		return (n * factorial(n - 1));
	}
	if (n == 0)
	{
		return (1);
	}
	return (-1);
}
