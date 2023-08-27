#include "main.h"

/**
 * _pow_recursion - return power of a number
 * @x: number to be powered
 * @y: numer powered by
 *
 * Return: the power of a number
 */

int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	if (y > 0)
		return (x * _pow_recursion(x, y - 1));
	return (-1);
}
