#include <stdio.h>

/**
 * main - prints all numbers separated by commas and space
 * Return: 0 on success
 */

int main(void)
{
	char number = '0';

	while (number <= '9')
	{
		putchar(number);
		number++;
		if (number > '9')
		{
			break;
		}
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
