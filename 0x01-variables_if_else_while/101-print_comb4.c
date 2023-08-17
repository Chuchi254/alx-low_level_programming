#include <stdio.h>

/**
 * main - prints a set of 3 digits
 *
 * Return: 0 on success
 */

int main(void)
{
	int i, j, k;

	for (i = '0'; i < '8'; i++)
	{
		for (j = i + 1; j <= '8'; j++)
		{
			for (k = j + 1; k <= '9'; k++)
			{
				putchar(i);
				putchar(j);
				putchar(k);
				if (i == '7' && j == '8' && k == '9')
					break;
				putchar(',');
				putchar(' ');
			}
		}
	}
	return (0);
}
