#include <stdio.h>

/**
 * main - prints all numbers from 0 to 9 as characters
 *
 * Return: 0 on success
 */

int main(void)
{
	int number;

	for (number = 48; number <= 57; number++)
	{
		putchar(number);
	}
	putchar('\n');
	return (0);
}
