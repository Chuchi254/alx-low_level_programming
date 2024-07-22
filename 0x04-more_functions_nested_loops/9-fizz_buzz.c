#include <stdio.h>

/**
 * print_string - Prints a string using putchar
 * @str: The string to print
 */
void print_string(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

/**
 * print_number - Prints an integer using putchar
 * @n: The integer to print
 */
void print_number(int n)
{
	int temp, index;
	char buffer[4];
	char *p;

	temp = n;
	index = 0;

	if (n >= 100)
	{
		buffer[index++] = '0' + temp / 100;
		temp %= 100;
	}
	if (n >= 10 || n >= 100)
	{
		buffer[index++] = '0' + temp / 10;
		temp %= 10;
	}
	buffer[index++] = '0' + temp;
	buffer[index] = '\0';

	for (p = buffer; *p != '\0'; p++)
		putchar(*p);
}

/**
 * fizz_buzz - Prints numbers from 1 to 100 with FizzBuzz rules
 */
void fizz_buzz(void)
{
	char *fizz = "Fizz";
	char *buzz = "Buzz";
	char *fizzbuzz = "FizzBuzz";
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			print_string(fizzbuzz);
		else if (i % 3 == 0)
			print_string(fizz);
		else if (i % 5 == 0)
			print_string(buzz);
		else
			print_number(i);

		if (i != 100)
			putchar(' ');
	}
	putchar('\n');
}

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
	fizz_buzz();
	return (0);
}
