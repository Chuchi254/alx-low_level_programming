#include "main.h"

/**
 * _memcpy - copies first n bytes of memory area pointed by src to dest
 * @src: string to be copied from
 * @dest: string copied to
 * @n: number of bytes
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int count = 0;

	if (src == NULL)
		return (NULL);
	while (count < n)
	{
		dest[count] = src[count];
		count++;
	}
	return (dest);
}
