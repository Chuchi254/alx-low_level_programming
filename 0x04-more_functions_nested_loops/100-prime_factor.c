#include <stdio.h>

/**
 * print_number - prints a number using putchar
 * @n: The number to print
 */

void print_number(long n)
{
	if (n / 10)
		print_number(n / 10);
	putchar((n % 10) + '0');
}

/**
 * main - finds and prints the largest prime factor of 612852475143
 * Return: Always 0 (Success)
 */

int main(void)
{
	long number = 612852475143;
	long factor = 2;
	long largest_factor = 0;

	while (number != 1)
	{
		if (number % factor == 0)
		{
			largest_factor = factor;
			while (number % factor == 0)
				number /= factor;
		}
		factor++;
		if (factor * factor > number && number > 1)
		{
			largest_factor = number;
			break;
		}
	}

	print_number(largest_factor);
	putchar('\n');
	return (0);
}
