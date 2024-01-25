#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints the name through a pointer to a function
 *
 * @name: string to be printed
 * @f: pointer to the print_name function
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
