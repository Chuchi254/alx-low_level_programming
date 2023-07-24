#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints characters on the stdout
 * Return: 1 
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
