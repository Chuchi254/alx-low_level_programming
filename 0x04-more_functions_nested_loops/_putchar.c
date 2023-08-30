#include "main.h"

/**
 * _putchar - writes a single character to the stdout
 * @c: input
 *
 * Return: 0 on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
