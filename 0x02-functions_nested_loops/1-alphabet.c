#include "main.h"
/**
 * print_alphabet - prints the letters of hte alphabet in lowercase
 * Return: 0 on success
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');
}
