#include <stdio.h>

/**
 * main - prints numbers from 0 to 9
 *
 * Return: 0 on success
 */

int main(void)
{
	int number;

	for (number = 0; number <= 9; number++)
	{
		printf("%d", number);
	}
	printf("\n");
	return (0);
}
