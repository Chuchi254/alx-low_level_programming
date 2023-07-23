#include <stdio.h>

/**
 * main - prints the lower case letter in reverse
 *
 * Return: 0 on success
 */

int main(void)
{
	char alphabet;

	for (alphabet = 'z'; alphabet >= 'a'; alphabet--)
	{
		putchar(alphabet);
	}
	putchar('\n');
	return (0);
}
