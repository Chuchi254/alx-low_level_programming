#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints character to the stdout
 * @c: character to be printed
 * Return: 0 Always
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
