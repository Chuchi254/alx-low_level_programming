#include "variadic_functions.h"

/**
 * sum_them_all - calculates the sum of input argument
 *
 * @n: number of arguments
 * @...: variable number of parameters to include
 * Return: returns sum of argument on success
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return (sum);
}
