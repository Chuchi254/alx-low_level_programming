#include <stdio.h>

/**
 * main - prints all numbers separated by commas and space
 * Return: 0 on success
 */

int main(void)
{
	int number = 48;

	while (number <= 57)
	{
		putchar(number);
		number++;
		if (number > 57)
		{
			break;
		}
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
