#include "main.h"

/**
 * _putchar - prints a character to the stdout
 * @c: character to be printed
 *
 * Return: 1 on success
 * on error return -1 and set errno appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
