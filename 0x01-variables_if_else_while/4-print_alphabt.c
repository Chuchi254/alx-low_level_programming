#include <stdio.h>

/**
 * main - prints all the letter in lower case except q and e
 *
 * Return: 0 on success
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (letter == 'q' || letter == 'e')
		{
			continue;
		}
		putchar(letter);
	}
	putchar('\n');
	return (0);
}
