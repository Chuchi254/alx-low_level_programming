#include <stdio.h>

/**
 * main - prints all numbers from 0 to 9 as characters
 *
 * Return: 0 on success
 */

int main(void)
{
	char number;

	for (number = '0'; number <= '9'; number++)
	{
		putchar(number);
	}
	putchar('\n');
	return (0);
}
