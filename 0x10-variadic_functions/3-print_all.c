#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_string - prints string
 * @str: points to string to be printed
 */

void print_string(char *str)
{
	if (str == NULL)
		str = "(nil)";
	while (*str)
		putchar(*str++);
}

/**
 * print_number - prints number
 * @n: number print
 */

void print_number(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		print_number(n / 10);
	putchar((n % 10) + '0');
}

/**
 * print_float - prints float
 * @f: float to be printed
 */

void print_float(double f)
{
	int integer_part = (int)f;
	int decimal_part = (int)((f - integer_part) * 10);

	print_number(integer_part);
	putchar('.');
	print_number(decimal_part);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *sep = "";

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				putchar(*sep);
				putchar(' ');
				putchar(va_arg(args, int));
				break;
			case 'i':
				putchar(*sep);
				putchar(' ');
				print_number(va_arg(args, int));
				break;
			case 'f':
				putchar(*sep);
				putchar(' ');
				print_float(va_arg(args, double));
				break;
			case 's':
				putchar(*sep);
				putchar(' ');
				print_string(va_arg(args, char *));
				break;
			default:
				i++;
				continue;
		}
		sep = ",";
		i++;
	}
	va_end(args);
	putchar('\n');
}
