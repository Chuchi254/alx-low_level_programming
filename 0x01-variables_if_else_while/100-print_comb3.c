#include <stdio.h>

/**
 * main - prints combination of 2 digits
 *
 * Return: 0 on success
 */

int main(void)
{
	int firstDigit, lastDigit;

	for (firstDigit = 48; firstDigit <= 56; firstDigit++)
	{
		for (lastDigit = 49; lastDigit <= 57; lastDigit++)
		{
			if (firstDigit == lastDigit)
			{
				continue;
			}
			putchar(firstDigit);
			putchar(lastDigit);
			if (firstDigit == 56 && lastDigit == 57)
			{
				break;
			}
			putchar(',');	
			putchar(' ');
		
		}
	}
	putchar('\n');
	return (0);
}
