#include "main.h"

/**
 * _memset - fills the first n bytes with b in the memory area pointed by s
 * @b: constant character
 * @s: string to be filled with b
 * @n: size of byte filled
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count = 0;

	while (count < n)
	{
		s[count] = b;
		count++;
	}
	return (s);
}
