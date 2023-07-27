#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints character c  to the stdout
 *
 * @char: character to be printed
 *
 * Return: 1 on sucess 
 * On error, -1 is returned and errno set appropriately.
 *
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
